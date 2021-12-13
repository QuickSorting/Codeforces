#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long long ll;
const int MOD = 998244353;
const int N = 1e6 + 3;

int n;
ll dp[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    ll sum = 2;
    dp[0] = 1;
    dp[1] = 1;
    for(int i = 2; i <= n; ++i){
        dp[i] = 1;
        dp[i] += sum;
        if(dp[i] >= MOD) dp[i] -= MOD;
        sum += dp[i];
        if(sum >= MOD) sum -= MOD;
    }
    cout << dp[n] << "\n";
}