#include <bits/stdc++.h>
#pragma GCC optimize("O3")

using namespace std;

typedef long long ll;
const int N = 150 + 3;
const int Y = 10 + 3;
const int X = 50 + 3;
const int MOD = 998244353;

ll dp[N][Y][X];
int n, x, y, a[N];
map<vector<int>, int> mp;

ll solve(const vector<int> &v){
    for(int i = n + 1; i >= n + 1; --i)
        for(int j = y; j >= 0; --j)
            for(int r = 0; r < x; ++r)
                dp[i][j][r] = (r == 0 && j == y);

    for(int i = n; i >= 1; --i){
        for(int j = y; j >= 0; --j){
            for(int r = 0; r < x; ++r){
                auto &ans = dp[i][j][r];
                if(j == y){
                    ans = (r == 0);
                    continue;
                }

                ans = dp[i + 1][j][r];
                ans += dp[i + 1][j + 1][(r + 2 * x + v[j] * a[i]) % x];
                if(ans >= MOD) ans -= MOD;
            }
        }
    }

    return dp[1][0][0];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> x >> y;
    a[1] = 0;
    for(int i = 2; i <= n; ++i){
        int t;
        cin >> t;
        a[i] += t;
        a[i] %= x;
    }

    vector<int> v, cnt(y);
    for(int i = 0; i < y; ++i)
        v.push_back(i);
    do{
        fill(cnt.begin(), cnt.end(), 0);
        for(int i = 0; i < y - 1; ++i){
            if(v[i] < v[i + 1]){
                --cnt[v[i]];
                ++cnt[v[i + 1]];
            }
            else{
                ++cnt[v[i]];
                --cnt[v[i + 1]];
            }
        }
        ++mp[cnt];
    }
    while(next_permutation(v.begin(), v.end()));

    ll ans = 0;
    for(auto &[v, cnt]: mp)
        ans = (ans + (ll)cnt * solve(v)) % MOD;
    cout << ans << "\n";
}