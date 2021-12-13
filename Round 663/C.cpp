#include <bits/stdc++.h>

using namespace std;

const long long k_Mod = 1e9 + 7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    long long f = 1, t = 1;
    for(long long i = 1; i <= n; ++i){
        f *= i;
        f %= k_Mod;

        if(i == n) continue;
        t <<= 1;
        t %= k_Mod;
    }

    f -= t;
    if(f < 0) f += k_Mod;

    cout << f << "\n";
}