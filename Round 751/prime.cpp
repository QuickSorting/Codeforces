#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }
#define all(x) (x).begin(), (x).end()

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int cnt = 0;
    for(int i = 2; true; ++i){
        bool ok = true;
        for(int j = 2; j * j <= i; ++j)
            if(i % j == 0)
                ok = false;
        if(ok) ++cnt;
        if(cnt == 2021){
            cout << i << endl;
            return 0;
        }
    }
}