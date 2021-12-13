#include <bits/stdc++.h>

using namespace std;

const int k_N = 5000 + 3;
const long long k_Mod = 998244353;

long long answer[k_N];
long long dp[k_N][k_N], dp2[k_N][k_N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for(int i = 1; i <= n; ++i)
        dp[n + 1][i] = 1;

    for(int i = n; i >= 1; --i)
        for(int j = 1; j <= n; ++j)
            dp[i][j] = ((dp[i + 1][j] * j % k_Mod) + dp[i + 1][j + 1]) % k_Mod;

    dp2[2][1] = 1;
    for(int i = 2; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            dp2[i + 1][j] += dp2[i][j] * j % k_Mod;
            dp2[i + 1][j] %= k_Mod;

            dp2[i + 1][j + 1] += dp2[i][j];
            dp2[i + 1][j + 1] %= k_Mod;
        }
    }

    for(int i = 1; i <= n + 1; ++i){
        for(int j = 1; j <= n; ++j){
            cout << dp[i][j] << " - " << dp2[i][j] << " i j " << i << " " << j << endl;
        }
    }

    answer[1] += dp[2][1];
    answer[1] %= k_Mod;

    for(int i = n; i >= 2; --i){
        for(int j = 1; j <= n; ++j){
            answer[j] += (dp[i + 1][j] * dp2[i][j] % k_Mod);
            answer[j] %= k_Mod;

            answer[j + 1] += dp[i + 1][j + 1] * dp2[i][j] % k_Mod;
            answer[j + 1] %= k_Mod;

            answer[j] -= dp[i + 1][j + 1] * dp2[i][j] % k_Mod;
            answer[j] += k_Mod;
            answer[j] %= k_Mod;
        }
    }

    for(int i = n - 1; i >= 1; --i){
        answer[i] += answer[i + 1];
        answer[i] %= k_Mod;
    }

    for(int i = 1; i <= n; ++i)
        cout << answer[i] << " ";
    cout << "\n"; 
}