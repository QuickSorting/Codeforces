#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        string s;
        int x, n;

        cin >> s >> x;
        n = s.size();

        string ans;
        ans.resize(n);
        for(int i = 0; i < n; ++i)
            ans[i] = '1';

        for(int i = 0; i < n; ++i){
            if(s[i] == '0'){
                if(i - x >= 0) ans[i - x] = '0';
                if(i + x < n) ans[i + x] = '0';
            }
        }

        bool ok = true;
        for(int i = 0; i < n; ++i){
            int t = 0;
            if(i - x >= 0 && ans[i - x] == '1')
                t = 1;
            if(i + x < n && ans[i + x] == '1')
                t = 1;

            if(s[i] - '0' != t){
                ok = false;
                break;
            }
        }

        if(!ok){
            cout << "-1\n";
            continue;
        }

        cout << ans << "\n";
    }
}