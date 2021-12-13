#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define all(x) (x).begin(), (x).end()

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        int n;
        string s;
        cin >> n >> s;

        for(int i = 1; i < (int)s.size(); ++i){
            if(s[i - 1] == '?') continue;
            if(s[i] == '?')
                s[i] = (s[i - 1] == 'R') ? 'B' : 'R';
        }
        for(int i = (int)s.size() - 2; i >= 0; --i){
            if(s[i + 1] == '?') continue;
            if(s[i] == '?')
                s[i] = (s[i + 1] == 'R') ? 'B' : 'R';
        }
        for(int i = 0; i < s.size(); ++i)
            if(s[i] == '?')
                s[i] = (i & 1) ? 'R' : 'B';
        cout << s << "\n";
    }
}