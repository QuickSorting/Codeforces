#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MOD = 998244353;

const int N = 1e6 + 3;

int n;
ll f[N], inv_f[N], pw[N], sum_odd[N], sum_even[N];

ll fast_pow(ll base, ll exp){
    if(!exp) return 1;
    if(exp & 1) return base * fast_pow(base, exp - 1) % MOD;
    ll t = fast_pow(base, exp >> 1);
    return t * t % MOD;
}

ll comb(ll n, ll k){
    return f[n] * inv_f[k] % MOD * inv_f[n - k] % MOD;
}

void solve(){
    cin >> n;

    ll ans = 0;

    int even = n / 2 + 1;
    int odd = (n + 1) / 2;
    for(int i = 1; i <= min(even, odd); ++i){
        ans = (ans + comb(even, i) * comb(odd, i) % MOD * 2 * i) % MOD;
    }

    sum_even[even] = 1;
    for(int i = even - 1; i >= 0; --i){
        sum_even[i] = (sum_even[i + 1] + comb(even, i)) % MOD;
    }

    sum_odd[odd] = 1;
    for(int i = odd - 1; i >= 0; --i){
        sum_odd[i] = (sum_odd[i + 1] + comb(odd, i)) % MOD;
    }

    for(int i = 0; i <= min(even, odd); ++i){
        if(odd > i){
            ans = (ans + comb(even, i) * sum_odd[i + 1] % MOD * i) % MOD;
        }
        if(even > i){
            ans = (ans + comb(odd, i) * sum_even[i + 1] % MOD * i) % MOD;
        }
    }
    cout << ans << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    f[0] = 1;
    for(int i = 1; i < N; ++i)
        f[i] = f[i - 1]  * i % MOD;
    inv_f[N - 1] = fast_pow(f[N - 1], MOD - 2);
    for(int i = N - 2; i >= 0; --i)
        inv_f[i] = inv_f[i + 1] * (i + 1) % MOD;
    pw[0] = 1;
    for(int i = 1; i < N; ++i)
        pw[i] = pw[i - 1] * 2 % MOD;

    while(t--) solve();
}