#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 3;
const int MOD = 998244353;

int n, m;
vector<int> adj[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i = 0; i < m; ++i){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
}