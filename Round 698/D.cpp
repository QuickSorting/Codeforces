#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 3;

int n, m, idx[N], root[N], p[N], q[N];
int new_n;
set<int> adj[N], s;
vector<int> r_adj[N];
vector<set<int>> stars;

void dfs(int u){
    //cout << "dfs " << u << endl;
    s.erase(u);
    vector<int> children;
    for(int to: s)
        if(!adj[u].count(to))
            children.push_back(to);
    
    for(int to: children){
        s.erase(to);
        r_adj[u].push_back(to);
        r_adj[to].push_back(u);
        dfs(to);
    }
}

void dfs_2(int u, int p = -1){
    //cout << "dfs_2 " << u << " " << p << endl;
    if(idx[u] == -1){
        for(int to: r_adj[u])
            if(idx[to] == -1){
                if(idx[u] == -1){
                    idx[u] = stars.size();
                    root[stars.size()] = u;
                    stars.push_back({});
                    stars.back().insert(u);
                }
                idx[to] = (int)stars.size() - 1;
                stars.back().insert(to);
            }

        if(idx[u] == -1){
            int to = r_adj[u][0];
            if(stars[idx[to]].size() > 2){
                stars[idx[to]].erase(to);
                idx[to] = idx[u] = stars.size();
                root[stars.size()] = u;
                stars.push_back({});
                stars.back().insert(to);
                stars.back().insert(u);
            }
            else{
                root[idx[to]] = to;
                stars[idx[to]].insert(u);
                idx[u] = idx[to];
            }
        }
    }

    for(int to: r_adj[u])
        if(to != p)
            dfs_2(to, u);
}

void clear(){
    s.clear();
    stars.clear();
    for(int i = 1; i <= n; ++i){
        adj[i].clear();
        r_adj[i].clear();
        s.insert(i);
        idx[i] = -1;
        root[i] = -1;
    }
}

void solve(){
    cin >> n >> m;
    clear();
    for(int i = 0; i < m; ++i){
        int x, y;
        cin >> x >> y;
        adj[x].insert(y);
        adj[y].insert(x);
    }

    int cnt = 1;
    for(int i = 1; i <= n; ++i)
        if(s.count(i)){
            if(adj[i].size() == n - 1){
                s.erase(i);
                p[i] = q[i] = cnt++;
                continue;
            }
            dfs(i);
            dfs_2(i);
        }

    for(int i = 0; i < stars.size(); ++i){
        cout << root[i] << " - ";
        for(int x: stars[i])
            cout << x << " ";
        cout << endl;
    }

    for(int i = 0; i < stars.size(); ++i){
        vector<int> v;
        //v.push_back(root[i]);
        for(int x: stars[i])
            if(x != root[i])
                v.push_back(x);

        p[root[i]] = cnt;
        q[root[i]] = cnt + stars[i].size() - 1;

        for(int j = 0; j < v.size(); ++j){
            p[v[j]] = cnt + j + 1;
            q[v[j]] = cnt + j;
        }

        cnt += stars[i].size();
    }

    for(int i = 1; i <= n; ++i) cout << p[i] << " ";
    cout << "\n";
    for(int i = 1; i <= n; ++i) cout << q[i] << " ";
    cout << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--) solve();
}