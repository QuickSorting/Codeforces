#include <bits/stdc++.h>
#pragma GCC optimize("O3")

using namespace std;

typedef long long ll;
const int N = 4e6 + 3;

int n, m;
int dp[N];
vector<int> divisors[N];

inline void fix(int &x){
    x = (x >= m) ? (x - m) : x;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for(int i = 2; i <= n; ++i)
        for(int j = i; j <= n; j += i)
            divisors[j].push_back(i);

    dp[1] = 1;
    int sum = 1, oth = 0;
    for(int i = 2; i <= n; ++i){
        dp[i] = sum;
        for(int d: divisors[i]){
            oth -= dp[i / d - 1];
            oth += dp[i / d];
            if(oth < 0) oth += m;
            if(oth >= m) oth -= m;
        }
        dp[i] += oth;
        fix(dp[i]);
        sum += dp[i];
        fix(sum);
    }
    cout << dp[n] << "\n";
}