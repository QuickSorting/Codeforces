#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 3;

int n, k, a[N], cnt[N];

void solve(){
    cin >> n >> k;
    fill(cnt + 1, cnt + 1 + n, 0);
    for(int i = 1; i <= n; ++i){
        int x;
        cin >> x;
        ++cnt[x];
    }

    int ans = 0, lft = 0;
    for(int i = 1; i <= n; ++i){
        if(cnt[i] > k) ++ans;
        else lft += cnt[i]; 
    }
    ans += lft / k + !!(lft % k);
    cout << ans << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--) solve();
}