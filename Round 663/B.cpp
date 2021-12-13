#include <bits/stdc++.h>

using namespace std;

const int k_N = 100 + 3;

string s[k_N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        int n, m;
        cin >> n >> m;

        for(int i = 0; i < n; ++i)
            cin >> s[i];
    
        int ans = 0;
        for(int i = 0; i < n - 1; ++i)
            ans += s[i][m - 1] != 'D';

        for(int i = 0; i < m - 1; ++i)
            ans += s[n - 1][i] != 'R';

        cout << ans << "\n";
    }
}