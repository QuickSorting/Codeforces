#include <bits/stdc++.h>
#pragma GCC optimize("O3")

using namespace std;

typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }
#define all(x) (x).begin(), (x).end()

const int N = 100 + 3;

int n, m, k, p;
ll comb[N][N], f[N];
ll dp[N][N][N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k >> p;
    --m;
    comb[0][0] = 1;
    for(int i = 1; i < N; ++i){
        comb[i][0] = 1;
        for(int j = 1; j <= i; ++j)
            comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % p;
    }
    f[0] = 1;
    for(int i = 1; i < N; ++i)
        f[i] = f[i - 1] * i % p;


    for(int add = m; add >= 1; --add){
        for(int n = 0; n <= ::n; ++n){
            for(int k = 0; k <= ::k; ++k){
                auto &ans = dp[add][n][k];
                if(!n){
                    ans = !k;
                }
                else if(add == m){
                    if(k == 1) ans = f[n];
                    else ans = 0;
                }
                if(!ans) continue;

                for(int n2 = 0; n2 + n + 1 <= ::n; ++n2)
                    for(int k2 = 0; k2 + k <= ::k; ++k2){
                        if(!dp[add][n2][k2]) continue;
                        auto &ans2 = dp[add][n2][k2];
                        auto &ans3 = dp[add - 1][n2 + n + 1][k2 + k];
                        ll to_add = ans * ans2 % p * comb[n2 + n][n];
                        if(n2 != n || k2 != k) to_add *= 2;
                        ans3 = (ans3 + to_add) % p;
                    }
            }
        }
    }

    cout << dp[0][n][k] << "\n";
}