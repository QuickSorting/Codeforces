#include <bits/stdc++.h>

using namespace std;

const int k_N = 5e5 + 3;

int n, m;
vector<int> adj[k_N];
bool vis[k_N];

vector<int> path_to_root;
vector<int> d[k_N];

bool dfs(int u){
    path_to_root.push_back(u);
    vis[u] = true;
    if(2 * path_to_root.size() >= n)
        return true;

    d[path_to_root.size()].push_back(u);

    for(int to: adj[u]){
        if(vis[to]) continue;
        if(dfs(to)) return true;
    }

    path_to_root.pop_back();
    return false;
}

void solve(){
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
        adj[i].clear();

    for(int i = 0; i < m; ++i){
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i = 1; i <= n; ++i){
        vis[i] = false;
        d[i].clear();
    }
    path_to_root.clear();

    if(dfs(1)){
        cout << "PATH\n";
        cout << path_to_root.size() << "\n";
        for(int u: path_to_root)
            cout << u << " ";
        cout << "\n";
        return;
    }

    cout << "PAIRING\n";
    vector<pair<int, int>> pairs;
    for(int i = 1; i <= n; ++i){
        for(int j = 0; j < (int)d[i].size() - 1; j += 2){
            pairs.push_back({d[i][j], d[i][j + 1]});
        }
    }

    cout << pairs.size() << "\n";
    for(auto [a, b]: pairs)
        cout << a << " " << b << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--) solve();
}