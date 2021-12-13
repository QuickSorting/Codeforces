#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        int n, k;
        cin >> n >> k;

        vector<int> ans;
        for(int i = k / 2 + (k & 1); i <= k - 1; ++i)
            ans.push_back(i);
        for(int i = k + 1; i <= n; ++i)
            ans.push_back(i);
        cout << ans.size() << "\n";
        for(int x: ans)
            cout << x << " ";
        cout << "\n";
    }
}