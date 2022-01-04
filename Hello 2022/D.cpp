#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }
#define all(x) (x).begin(), (x).end()

const int N = 500 + 3;
const ll INF = 1e18;

int n;
ll c[N][N], p[N][N], ans[N][N];

void init(){
    for(int i = 1; i <= 2 * n; ++i)
        for(int j = 1; j <= 2 * n; ++j)
            p[i][j] = c[i][j] +  p[i][j - 1] + p[i - 1][j] - p[i - 1][j - 1];
}

ll query(int x1, int y1, int x2, int y2){
    return p[x2][y2] - p[x1 - 1][y2] - p[x2][y1 - 1] + p[x1 - 1][y1 - 1];
}

void solve(){
    cin >> n;
    for(int i = 1; i <= 2 * n; ++i)
        for(int j = 1; j <= 2 * n; ++j)
            cin >> c[i][j];

    init();

    for(int i = 1; i <= 2 * n; ++i)
        for(int j = 1; j <= 2 * n; ++j)
            ans[i][j] = INF;

    priority_queue<array<ll, 3>, vector<array<ll, 3>>, greater<array<ll, 3>>> pq;
    pq.push({0, 1, 1});
    ans[1][1] = 0;

    while(!pq.empty()){
        auto [d, x, y] = pq.top();
        pq.pop();

        //cout << d << " " << x << " " << y << " d x y" << endl;

        if(x == n + 1 && y == n + 1){
            cout << d << "\n";
            return;
        }
        if(ans[x][y] != d)
            continue;

        if(x != n + 1){
            ll cand = d + query(x + n, y, x + n, y + n - 1);
            if(cand < ans[x + 1][y]){
                ans[x + 1][y] = cand;
                pq.push({cand, x + 1, y});
            }
        }
        if(y != n + 1){
            ll cand = d + query(x, y + n, x + n - 1, y + n);
            if(cand < ans[x][y + 1]){
                ans[x][y + 1] = cand;
                pq.push({cand, x, y + 1});
            }
        }
        if(x != n + 1 && y != n + 1 && n != 1){
            ll cand = d + query(x + n, y + 1, x + n, y + n) + query(x + 1, y + n, x + n, y + n) - c[x + n][y + n];
            if(cand < ans[x + 1][y + 1]){
                ans[x + 1][y + 1] = cand;
                pq.push({cand, x + 1, y + 1});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--)
        solve();
}