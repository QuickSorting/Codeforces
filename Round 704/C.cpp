#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;

    vector<int> pr(m + 1), su(m + 1);
    for(int i = 0, j = 0; i < n && j < m; ++i)
        if(s[i] == t[j])
            pr[j++] = i;
    for(int i = n - 1, j = m - 1; i >= 0 && j >= 0; --i)
        if(s[i] == t[j])
            su[j--] = i;
        
    int ans = 0;
    for(int i = 0; i < m - 1; ++i)
        ans = max(su[i + 1] - pr[i], ans);

    cout << ans << "\n";
}