#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }
#define all(x) (x).begin(), (x).end()

const ll N = 5e5 + 3;
const ll INF = 1e18;

ll n, q;
ll a[3][N], p[3][N];
array<ll, 3> quer[N];
ll ans = -INF;

ll dp[N];

ll get_sum(ll i, ll l, ll r){
    return p[i][r] - p[i][l - 1];
}

void dnc(ll l, ll r, ll sl, ll sr){
    if(l > r) return;
    if(sl > sr) return;

    if(r - l < sr - sl){
        ll mid = (l + r) >> 1;
        ll opt;
        ll x;
        for(ll i = mid; i <= sr; ++i){

        }

        check_max(ans, x);
        dnc(l, mid - 1, sl, opt);
        dnc(mid + 1, r, opt, sr);
    }
    else{
        ll mid = (sl + sr) >> 1;
        ll opt;
        ll x;
        for(ll i = mid; i >= l; --i){

        }

        check_max(ans, x);
        dnc(l, opt, sl, mid - 1);
        dnc(opt, r, mid + 1, r);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;
    for(ll i = 0; i < 3; ++i)
        for(ll j = 1; j <= n; ++j)
            cin >> a[i][j];

    for(ll i = 0; i < q; ++i){
        for(ll j = 0; j < 3; ++j)
            cin >> quer[i][j];
    }
    
    for(ll i = 0; i < 3; ++i){
        for(ll j = 1; j <= n; ++j)
            p[i][j] = p[i][j - 1] + a[i][j];
    }

    dnc(1, n, 1, n);
    cout << ans << "\n";
}