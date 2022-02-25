#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }
#define all(x) (x).begin(), (x).end()

int solve(int x){
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll ans = 0;
    for(int i = 1; i <= (int)1e9; ++i)
        ans += solve(i);
    cout << (long double)ans / (long double)1e9 << endl;
}