#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vector<int> v;
        for(int i = 0; i < n; ++i){
            int x;
            cin >> x;
            v.push_back(x);
        }

        sort(v.begin(), v.end());

        bool ok = false;
        for(int i = 0; i < n - 1; ++i){
            if(v[i] == v[i + 1]){
                ok = true;
                break;
            }
        }

        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
}