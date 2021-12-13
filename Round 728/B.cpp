#include <bits/stdc++.h>

using namespace std;

const int N = 200 + 3;
const int MOD = 1e9 + 7;

int n;
vector<int> adj[N];
bool ok[N];

long long fast_pow(long long base, long long exp){
    if(!exp) return 1;
    if(exp & 1) return fast_pow(base, exp - 1) * base % MOD;
    long long t = fast_pow(base, exp >> 1);
    return t * t % MOD;
}

int get_sz(int u, int p = -1){
    int sz = 1;
    for(int to: adj[u])
        if(to != p)
            sz += get_sz(to, u);
    return sz;
}

bool dfs(int start, int end, int p = -1){
    if(start == end) return ok[start] = true;
    for(int to: adj[start])
        if(to != p)
            ok[start] |= dfs(to, end, start);
    return ok[start];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n - 1; ++i){
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    
}