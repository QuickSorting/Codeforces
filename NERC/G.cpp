#include <bits/stdc++.h>

using namespace std;

const int N = 100 + 3;
const int INF = 1e9;

int dp[2 * N][N], p[N];
int n, k;
vector<int> adj[N];
vector<int> tour;
int start[N], en[N];

void euler_tour(int u, int p = -1){
    start[u] = tour.size();
    tour.push_back(u);
    for(int to: adj[u])
        if(to != p){
            euler_tour(to, u);
            tour.push_back(u);
        }
    en[u] = tour.size();
}

void solve(){
    cin >> n >> k;
    fill(adj, adj + n + 1, vector<int>());
    for(int i = 2; i <= n; ++i){
        cin >> p[i];
        adj[i].push_back(p[i]);
        adj[p[i]].push_back(i);
    }
    tour.clear();
    euler_tour(1);
    
    for(int j = 0; j <= k + 1; ++j){
        if(!j) dp[2 * n - 2][j] = 0;
        else dp[2 * n - 2][j] = INF;
    }

     // cout << "tour: ";
    // for(int x: tour)
        // cout << x << " ";
    // cout << endl;

    for(int i = 2 * n - 3; i >= 0; --i){
        for(int j = 0; j <= k; ++j){
            if(!j){
                dp[i][j] = 0;
                continue;
            }
            dp[i][j] = INF;
            if(i && i == start[tour[i]]) dp[i][j] = min(dp[en[tour[i]]][j + 1] - 1, dp[i][j]);
            //cout << dp[i][j] << " - " << i << " " << j << endl;
            //cout << (tour[i + 1] != p[tour[i]]) << endl;
            //cout << tour[i + 1] << " " << p[tour[i]] << " tours" << endl;
            if(tour[i + 1] != p[tour[i]]) dp[i][j] = min(1 + dp[i + 1][j - 1], dp[i][j]);
            else dp[i][j] = min(1 + dp[i + 1][j], dp[i][j]);
          
            //cout << dp[i][j] << " - " << i << " " << j << endl;
        }
        dp[i][k + 1] = INF;
    }
    cout << dp[0][k - 1] << "\n";
    int i = 0, j = k - 1;
    vector<int> ans;
    while(j){
        //cout << i << " " << j << " i j" << endl;
        int curr_0 = INF, curr_1 = INF;
        if(i && i == start[tour[i]]) curr_0 = dp[en[tour[i]]][j + 1] - 1;
        if(tour[i + 1] != p[tour[i]]) curr_1 = 1 + dp[i + 1][j - 1];
        else curr_1 = 1 + dp[i + 1][j];
        
        if(curr_0 < curr_1){
            i = en[tour[i]];
            ++j;
            ans.pop_back();
        }
        else{
            //if(i == start[tour[i]])
            // cout << tour[i] << " ";
            ans.push_back(tour[i]);
            if(tour[i + 1] != p[tour[i]]){
                ++i;
                --j;
            }
            else ++i;
        }
    }
    // cout << tour[i] << "\n";
    ans.push_back(tour[i]);
    for(int x: ans)
        cout << x << " ";
    cout << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--) solve();
}