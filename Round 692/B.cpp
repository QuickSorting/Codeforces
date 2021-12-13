#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 1e5 + 3;

string s;
ll x, y, n;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s >> x >> y;
    n = (int)s.size();

    if(x > y){
        swap(x, y);
        for(char &c: s){
            if(c == '?') continue;
            c = !(c - '0') + '0';
        }
    }

    ll ans = 0, curr = 0, l[2]{}, r[2]{};
    for(int i = 0; i < n; ++i){
        if(s[i] == '?') ++r[1];
        else ++r[s[i] - '0'];
    }

    for(int i = 0; i < n; ++i){
        if(s[i] == '?'){
            --r[1];
            curr -= l[0] * x + r[0] * y;
            curr += l[1] * y + r[1] * x;
            ans = min(ans, curr);
            ++l[1];
        }
        else{
            --r[s[i] - '0'];
            ++l[s[i] - '0'];
        }
    }

    swap(l[0], r[0]);
    swap(l[1], r[1]);

    for(int i = 0; i < n; ++i){
        if(s[i] == '?') s[i] = '1';

        --r[s[i] - '0'];

        if(s[i] == '0')
            ans += l[1] * y;
        else
            ans += l[0] * x;

        ++l[s[i] - '0'];
    }

    cout << ans << "\n";
}