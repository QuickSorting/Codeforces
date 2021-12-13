#include <bits/stdc++.h>

using namespace std;

struct dsu{
    int sz;
    vector<int> par, psz;

    dsu(){}

    void init(int n){
        sz = n;
        for(int i = 0; i <= sz; ++i){
            par.push_back(i);
            psz.push_back(1);
        }
    }

    int root(int u){
        return par[u] = (u == par[u]) ? u : root(par[u]);
    }
    bool connected(int x, int y){
        return root(x) == root(y);
    }

    void unite(int x, int y){
        x = root(x), y = root(y);
        if(x == y) return;
        if(psz[x] > psz[y]) swap(x, y);
        par[x] = y, psz[y] += psz[x];
    }
};

const int N = 1e6 + 3;

int n, m, q;
int p[N], removed[N], ver[N], smaller[N], used[N], TIMER = 0;
pair<int, int> e[N], que[N];
dsu d;
set<int> adj[N];
priority_queue<int> pq[2 * N];

void dfs(int u){
    if(p[u]) pq[TIMER].push(p[u]);
    used[u] = TIMER;

    for(int v: adj[u])
        if(used[v] != TIMER)
            dfs(v);
}

void create_new_comp(int u){
    TIMER++;
    dfs(u);
}

void solve(){
    d.init(n);
    for(int i = 1; i <= m; ++i)
        if(!removed[i])
            d.unite(e[i].first, e[i].second);

    for(int i = q; i >= 1; --i){
        smaller[i] = -1;

        int id = que[i].second;
        if(que[i].first == 2 && !d.connected(e[id].first, e[id].second)){
            int r1 = d.root(e[id].first), r2 = d.root(e[id].second);
            if(d.psz[r1] < d.psz[r2])
                smaller[i] = e[id].first;
            else
                smaller[i] = e[id].second;

            d.unite(e[id].first, e[id].second);
        }
    }

    for(int i = 1; i <= m; ++i){
        adj[e[i].first].insert(e[i].second);
        adj[e[i].second].insert(e[i].first);
    }

    for(int i = 1; i <= n; ++i)
        if(!used[i])
            create_new_comp(i);

    for(int i = 1; i <= q; ++i){
        if(que[i].first == 1){
            int comp = used[que[i].second];
            int ans = 0;

            while(!pq[comp].empty()){
                int cand = ver[pq[comp].top()];
                pq[comp].pop();

                if(used[cand] == comp && p[cand]){
                    ans = cand;
                    break;
                }
            }

            cout << p[ans] << endl;
            if(ans != 0) p[ans] = 0;
        }
        else{
            int id = que[i].second;
            adj[e[id].first].erase(e[id].second);
            adj[e[id].second].erase(e[id].first);

            if(smaller[i] != -1)
                create_new_comp(smaller[i]);
        }
    }
}

void read(){
    cin >> n >> m >> q;

    for(int i = 1; i <= n; ++i){
        cin >> p[i];
        ver[p[i]] = i;
    }

    for(int i = 1; i <= m; ++i)
        cin >> e[i].first >> e[i].second;

    for(int i = 1; i <= q; ++i){
        cin >> que[i].first >> que[i].second;
        if(que[i].first == 2)
            removed[que[i].second] = true;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    read();
    solve();
}