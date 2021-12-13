#include <bits/stdc++.h>
//#pragma GCC optimize("O3")

using namespace std;

typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }
#define all(x) (x).begin(), (x).end()

constexpr int N = 21 + 3;
constexpr int T = (1 << 23) + 3;
constexpr int MOD = 31607;
constexpr int C = 10000;

int n, a[N][N];
short dp[N][T];

int fast_pow(int base, int exp){
    if(!exp) return 1;
    if(exp & 1) return base * fast_pow(base, exp - 1) % MOD;
    int t = fast_pow(base, exp >> 1);
    return t * t % MOD;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            cin >> a[i][j];

    int rev = fast_pow(C, MOD - 2);
    int max_state = (1 << (n + 2));
    for(int i = n * n; i >= n * n; --i){
        int curr = i % (n + 1);
        for(int j = 0; j < max_state; ++j){
            short &ans = dp[curr][j];
            ans = j == max_state - 1;
        }
    }

    for(int i = n * n - 1; i >= 0; --i){
        int curr = i % (n + 1);
        int nxt = (i + 1) % (n + 1);
        int x = i / n, y = i % n;
        int or_state = (1 << y);

        if(x == y) or_state |= (1 << n);
        if(x + y == n - 1) or_state |= (1 << (n + 1));
        if(y){
            for(int j = 0; j < max_state; ++j){
                dp[curr][j] = ((int)dp[nxt][j] * a[x][y] + (int)dp[nxt][(j | or_state)] * (C - a[x][y])) % MOD;
            }
        }
        else{
            int t = 1;
            for(int k = 0; k < n; ++k)
                t = t * a[x][k] % MOD;
            for(int j = 0; j < max_state; ++j){
                dp[curr][j] = ((int)dp[nxt][j] * a[x][y] + (int)dp[nxt][(j | or_state)] * (C - a[x][y]) - (int)dp[(i + n) % (n + 1)][j] * t) % MOD;
                if(dp[curr][j] < 0) dp[curr][j] += MOD;
            }
        }
    }

    dp[0][0] = fast_pow(C, n * n) - dp[0][0];
    if(dp[0][0] < 0) dp[0][0] += MOD;
    dp[0][0] = (int)dp[0][0] * (int)fast_pow(rev, n * n) % MOD; 
    cout << dp[0][0] << "\n";
}