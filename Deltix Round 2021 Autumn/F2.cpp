#include <bits/stdc++.h>
#pragma GCC optimize("O3")

using namespace std;

typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }
#define all(x) (x).begin(), (x).end()

const int N = 1e6 + 3;

int n;
ll a[N];
vector<int> idx[64];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];

    for(int i = 1; i <= n; ++i)
        idx[__builtin_popcount(a[i])].push_back(i);

    ll ans = 0;
    for(int i = 1; i <= n; ++i){
        ll mn = a[i], mx = a[i];
        for(int j = i; j <= n; ++j){
            check_min(mn, a[j]);
            check_max(mx, a[j]);
            ans += __builtin_popcount(mn) == __builtin_popcount(mx);
        }
    }

    cout << ans << "\n";
}
