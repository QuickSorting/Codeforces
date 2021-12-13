#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll k_Mod = 998244353;
const int k_N = 3e5 + 3;

int n, m;
vector<int> adj[k_N];
int l[k_N], r[k_N];
vector<vector<array<int, 3>>> v;

void dfs(int u, int p = -1, array<int, 3> curr){
    v.push_back({curr});
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for(int i = 1; i <= n; ++i){
        cin >> l[i] >> r[i];
    }

    for(int i = 0; i < m; ++i){
        int x, y;
        cin >> x >> y;
        adj[x].push_back(x);
        adj[y].push_back(y);
    }

    v.push_back({});
    for(int i = 1; i <= n; ++i){
        if(adj[i].empty())
            v[0].push_back({1, l[i], r[i]});
        else if(!used[i]){
            v.push_back({});
            dfs(i, -1, {1, -k_N, k_N});
        }
    }
}