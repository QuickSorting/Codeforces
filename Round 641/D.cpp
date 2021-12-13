#include <bits/stdc++.h>

using namespace std;

const long long k_Mod = 998244353;
const int k_N = 100000 + 3;
const int k_Val = 300000 + 3;

int a[k_N];
long long dp[k_N];
int sum, n;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    sum = 0;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        sum += a[i];
    }

    dp[n] = 0;
}