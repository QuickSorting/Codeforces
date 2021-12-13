#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    cin >> q;

    while(q--){
        string s, t;
        cin >> s >> t;

        int lcm = s.size() * t.size() / __gcd(s.size(), t.size());
        bool ok = true;
        for(int i = 0; i < lcm; ++i){
            if(s[i % s.size()] != t[i % t.size()]){
                ok = false;
                break;
            }
        }

        if(ok){
            for(int i = 0; i < lcm / s.size(); ++i)
                cout << s;
            cout << "\n";
        }
        else cout << "-1\n";
    }
}