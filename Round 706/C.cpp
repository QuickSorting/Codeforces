#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }

const int N = 500 + 3;
int n, m;
string s[N];

void solve(){
    cin >> n >> m;
    for(int i = 0; i < n; ++i)
        cin >> s[i];
    for(int i = 0; i < n; ++i){
        if(i % 2 == 0){
            for(int j = 0; j < m; ++j)
                s[i][j] = 'X';
        }
        else{
            
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--) solve();
}