#include <bits/stdc++.h>

using namespace std;

const int N = 6 + 3;
const int M = 1e5 + 3;

int a[N], b[M];
int dp[N][M];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    const int n = 6;
    int m;
    cin >> m;

    for(int i = 0; i < n; ++i)
        cin >> a[i];

    for(int j = 0; j < m; ++j)
        cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    for(int i = n - 1; i >= 0; --i){
        for(int j = m - 1; j >= 0; --j){
            if()
        }
    }
}