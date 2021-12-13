#include <bits/stdc++.h>

using namespace std;

const int N = 3000 + 3;
const int M = 1e4 + 3;

typedef long long ll;
const ll INF = 1e18;

int n, m;
vector<pair<int, int>> adj[N];
ll dp[N][N];
bool vis[N];
int cnt_vis;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i = 0; i < m; ++i){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    for(int i = 2; i <= n; ++i)
        for(int j = 0; j <= n; ++j)
            dp[i][j] = INF;

    priority_queue<array<ll, 3>, vector<array<ll, 3>>, greater<array<ll, 3>>> pq;
    pq.push({0, 1, 1});

    while(!pq.empty()){
        auto [cost, u, cnt_e] = pq.top();
        pq.pop();

        if(cost > dp[u][cnt_e]) continue;
        if(!vis[u]){
            vis[u] = true;
            ++cnt_vis;
            if(cnt_vis == n) break;
        }

        for(auto [to, w]: adj[u]){
            ll cand = cost + cnt_e * w;
            if(dp[to][cnt_e + 1] > cand){
                dp[to][cnt_e + 1] = cand;
                pq.push({cand, to, cnt_e + 1});
            } 
        }
    }

    for(int i = 1; i <= n; ++i){
        ll ans = INF;
        for(int j = 1; j <= n; ++j)
            ans = min(ans, dp[i][j]);
        if(ans == INF) ans = -1;
        cout << ans << "\n";
    }
}