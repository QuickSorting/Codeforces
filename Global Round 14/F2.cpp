#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }
#define all(x) (x).begin(), (x).end()

const int N = 3e5 + 3;

int n, m, x;
ll a[N];
set<array<ll, 3>> s[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> x;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    for(int i = 0; i < m; ++i){
        int x, y;
        cin >> x >> y;
        s[x].push_back({a[y], y, i});
        s[y].push_back({a[x], x, i});
    }

    ll sum = 0;
    for(int i = 1; i <= n; ++i)
        sum += a[i];

    if(sum < (ll)(n - 1) * x){
        cout << "NO\n";
        return 0;
    }

    int big_idx = 0;
    for(int i = 1; i <= n; ++i)
        if(a[i] > a[big_idx])
            big_idx = i;

    priority_queue<array<ll, 3>, vector<array<ll, 3>>, array<ll, 3>> pq;
    while(!pq.empty()){
        
    } 
}