#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }
#define all(x) (x).begin(), (x).end()

const int N = 2e5 + 3;
const int INF = 1e9;

int n, ans[N], cnt[N];
vector<int> adj[N], rev_adj[N];

void solve(){
    cin >> n;
    fill(adj + 1, adj + 1 + n, vector<int>());
    fill(rev_adj + 1, rev_adj + 1 + n, vector<int>());
    fill(ans + 1, ans + 1 + n, 0);
    fill(cnt + 1, cnt + 1 + n, 0);

    for(int i = 1; i <= n; ++i){
        int k;
        cin >> k;
        for(int j = 1; j <= k; ++j){
            int from;
            cin >> from;
            adj[from].push_back(i);
            rev_adj[i].push_back(from);
        }
    }

    queue<int> q;
    for(int i = 1; i <= n; ++i)
        if(cnt[i] == rev_adj[i].size()){
            q.push(i);
            ans[i] = 1;
        }

    while(!q.empty()){
        int x = q.front();
        q.pop();

        for(int to: adj[x]){
            ++cnt[to];
            check_max(ans[to], ans[x] + (to < x));
            if(cnt[to] == rev_adj[to].size())
                q.push(to);
        }
    }

    for(int i = 1; i <= n; ++i)
        if(!ans[i]){
            cout << "-1\n";
            return;
        }

    int mx = 0;
    for(int i = 1; i <= n; ++i)
        check_max(mx, ans[i]);

    cout << mx << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    for(int i = 1; i <= t; ++i)
        solve();
}
/*
1
4
1 4
1 3
0
2 2 3
*/
