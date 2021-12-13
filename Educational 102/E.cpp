#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 2e5 + 3;

int n, m;
vector<array<int, 2>> adj[N];
ll d[N][2][2];
priority_queue<array<ll, 4>, vector<array<ll, 4>>, greater<array<ll, 4>>> pq;

void try_push(ll new_d, int to1, int to2, int to3){
    if(new_d < d[to1][to2][to3]){
        d[to1][to2][to3] = new_d;
        pq.push({new_d, to1, to2, to3});
    }
}

void dijkstra(){
    for(int i = 1; i <= n; ++i)
        for(int j = 0; j <= 1; ++j)
            for(int k = 0; k <= 1; ++k)
                d[i][j][k] = LLONG_MAX;

    
    pq.push({0, 1, 0, 0});
    d[1][0][0] = 0; 

    while(!pq.empty()){
        auto [du, u1, u2, u3] = pq.top();
        pq.pop();

        if(du > d[u1][u2][u3]) continue;

        for(auto [to, w]: adj[u1]){
            ll new_d = du + w;
            try_push(new_d, to, u2, u3);
            if(!u2) try_push(new_d - w, to, true, u3);
            if(!u3) try_push(new_d + w, to, u2, true);
            if(!u2 && !u3) try_push(new_d, to, true, true);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i = 0; i < m; ++i){
        int v, u, w;
        cin >> v >> u >> w;
        adj[v].push_back({u, w});
        adj[u].push_back({v, w});
    }

    dijkstra();

    for(int i = 2; i <= n; ++i)
        cout << d[i][1][1] << " ";
    cout << "\n";
}