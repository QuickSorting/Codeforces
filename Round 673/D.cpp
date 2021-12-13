#include <bits/stdc++.h>

using namespace std;

const int k_N = 5e5 + 3;

int n, m, q;
int p[k_N];
array<int, 2> e[k_N];

array<int, 2> quer[k_N];

bool rem[k_N];
vector<int> adj[k_N];

int cn = 1;
vector<int> ctree[k_N], idx[k_N];
int c_sz[k_N];
array<int, 2> lr[k_N];
int start_node[k_N];
bool root[k_N];

bool vis[k_N];

int sz[k_N], par[k_N], dsu_node[k_N];

int q_ptr[k_N];

int pos_st[k_N];

struct SegmentTree1{
    int a[4 * k_N];

    SegmentTree1(){
        for(int i = 0; i < 4 * k_N; ++i)
            a[i] = -1;
    }

    void push(int i, int l, int r){
        if(l != r && a[i] != -1){
            a[2 * i + 1] = a[i];
            a[2 * i + 2] = a[i];
        }
        a[i] = -1;
    }

    void update(int i, int l, int r, int sl, int sr, int x){
        push(i, l, r);
        if(l > sr || r < sl) return;
        if(sl <= l && r <= sr){
            a[i] = x;
            return;
        }

        int mid = (l + r) >> 1;
        update(2 * i + 1, l, mid, sl, sr, x);
        update(2 * i + 2, mid + 1, r, sl, sr, x);

        a[i] = -1;
    }

    int find_c(int i, int l, int r, int s){
        push(i, l, r);
        if(l > s || r < s) return -1;
        if(l == r) return a[i];

        int mid = (l + r) >> 1;
        int lval = find_c(2 * i + 1, l, mid, s);
        int rval = find_c(2 * i + 2, mid + 1, r, s);

        return max(lval, rval);
    }
};

struct SegmentTree2{
    array<int, 2> a[4 * k_N];

    SegmentTree2(){
        for(int i = 0; i < 4 * k_N; ++i)
            a[i] = {0, -1};
    }


    void update(int i, int l, int r, int s, int x){
        if(l > s || r < s) return;
        if(l == r){
            a[i] = {x, i};
            return;
        }

        int mid = (l + r) >> 1;
        update(2 * i + 1, l, mid, s, x);
        update(2 * i + 2, mid + 1, r, s, x);

        a[i] = max(a[2 * i + 1], a[2 * i + 2]);
    }

    array<int, 2> query(int i, int l, int r, int s){
        if(l > s || r < s) return {0, -1};
        if(l == r) return a[i];

        int mid = (l + r) >> 1;
        auto lval = query(2 * i + 1, l, mid, s);
        auto rval = query(2 * i + 2, mid + 1, r, s);

        return max(lval, rval);
    }
};

void build_tree(int u, int l, int r){
    lr[u] = {l, r};

    if(ctree[u].empty()){
        for(int i = 0; i < idx[u].size(); ++i)
            pos_st[idx[u][i]] = l + i;
        return;
    }

    for(int to: ctree[u]){
        build_tree(to, l, l + c_sz[to] - 1);
        l += c_sz[to];
    }
}

int find_par(int x){
    if(par[x] == x) return x;
    return par[x] = find_par(par[x]);
}

bool unite(int u, int v){
    if(find_par(u) == find_par(v))
        return false;

    if(sz[par[u]] < sz[par[v]])
        swap(u, v);

    sz[par[u]] += sz[par[v]];
    par[par[v]] = par[u];
    return true;
}

void dfs(int u, int cidx){
    idx[cidx].push_back(u);
    vis[u] = true;
    start_node[u] = cidx;

    for(int to: adj[u]){
        if(rem[to]) continue;
        dfs(to, cidx);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> q;
    for(int i = 1; i <= n; ++i)
        cin >> p[i];

    for(int i = 1; i <= m; ++i)
        cin >> e[i][0] >> e[i][1];

    for(int i = 1; i <= q; ++i){
        cin >> quer[i][0] >> quer[i][1];
        if(quer[i][0] == 2)
            rem[quer[i][1]] = true;
    }

    for(int i = 1; i <= q; ++i){
        if(!rem[i]){
            adj[quer[i][0]].push_back(quer[i][1]);
            adj[quer[i][1]].push_back(quer[i][0]);
        }
    }

    for(int i = 1; i <= n; ++i){
        if(!vis[i]){
            dfs(i, cn);
            cn++;
        }
    }

    for(int i = 1; i <= n; ++i){
        sz[i] = 1;
        par[i] = i;
        dsu_node[i] = start_node[i];
    }

    for(int i = 1; i < cn; ++i){
        c_sz[i] = idx[i].size();
        root[i] = true;
    }

    for(int i = 1; i < cn; ++i)
        for(int j = 0; j < (int)idx[i].size() - 1; ++j)
            unite(idx[i][j], idx[i][j + 1]);

    for(int i = q; i >= 1; --i){
        if(quer[i][0] == 2){
            auto [u, v] = e[quer[i][1]];
            if(unite(u, v)){
                int l = dsu_node[par[u]];
                int r = dsu_node[par[v]];

                ctree[cn].push_back(l);
                ctree[cn].push_back(r);
                q_ptr[i] = cn;
                c_sz[cn] = c_sz[l] + c_sz[r];

                root[l] = false;
                root[r] = false;
                root[cn] = true;

                dsu_node[find_par(u)] = cn;
                cn++;
            }
        }
    }

    int curr = 1;
    for(int i = 1; i < cn; ++i){
        if(root[i]){
            build_tree(i, curr, curr + c_sz[i] - 1);
            curr += c_sz[i];
        }
    }

    for(int i = 1; i <= q; ++i){
        if(type == 2){
            
        }
    }
}