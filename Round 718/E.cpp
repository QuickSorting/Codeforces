#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
template<class T> void check_min(T &a, const T b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T b){ a = (a > b) ? a : b; }
#define all(x) (x).begin(), (x).end()

const int N = 2e5 + 3;
const int MOD = 998244353;

int n, a[N];
ll sum[N], sum_alt[N];

ll get_sum(int l, int r){
    if(l > r) return 0;
    if(!l) return sum[r];
    return sum[r] - sum[l - 1];
}

ll get_alt_sum(int l, int r){
    if(l > r) return 0;
    assert((r - l) & 1);
    if(!l) return -sum_alt[r];
    return -sum_alt[r] + sum_alt[l - 1];
}

ll solve(int l, int r, ll sum){
    if(l > r) return sum > 0;

    ll ans = 0;
    int ptr = ((r - l) & 1) ? r : r - 1;
    for(int i = l; i <= r; i += 2){
        while(ptr >= i + 3 && get_alt_sum(i + 1, ptr - 1) - get_sum(l, i) + get_sum(ptr, r) <= 0)
            ptr -= 2;
        if(ptr < i + 3) continue;
        ans += (ptr - (i + 3)) / 2 + 1;
    }

    ptr = ((r - l) & 1) ? r - 1 : r;
    for(int i = l + 1; i <= r; i += 2){
        while(ptr >= i + 3 && get_alt_sum(i + 1, ptr - 1) - get_sum(l, i) + get_sum(ptr, r) <= 0)
            ptr -= 2;
        if(ptr < i + 3) continue;
        ans += (ptr - (i + 3)) / 2 + 1;
    }

    return ans;
}

void solve(){
    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    if(n == 1){
        cout << 1 << "\n";
        return;
    }

    sum[0] = a[0];
    for(int i = 1; i < n; ++i)
        sum[i] = sum[i - 1] + a[i];

    sum_alt[0] = a[0];
    for(int i = 1; i < n; ++i)
        sum_alt[i] = a[i] - sum_alt[i - 1];

    ll ans = (ll)(solve(0, n - 1, 0) + solve(1, n - 1, a[0]) + solve(0, n - 2, -a[n - 1]) + solve(1, n - 2, a[0] - a[n - 1])) % MOD;
    for(int i = -1; i < n - 1; ++i){
        ll curr = get_sum(0, i) - get_sum(i + 1, n - 1);
        if(curr < 0) ++ans;
        if(curr > 0) ++ans;
    }
    for(int i = 1; i < n - 1; ++i){
        ll curr = a[0] - get_sum(1, i) + get_sum(i + 1, n - 1);
        if(curr > 0) ++ans;
    }
    for(int i = 1; i < n - 1; ++i){
        ll curr = -a[n - 1] + get_sum(i, n - 2) - get_sum(0, i - 1);
        if(curr > 0) ++ans;
    }
    for(int i = 1; i < n - 2; ++i){
        ll curr = a[0] - a[n - 1] - get_sum(1, i) + get_sum(i + 1, n - 2);
        if(curr > 0) ++ans;
    }
    ans %= MOD;

    cout << ans << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--) solve();
}