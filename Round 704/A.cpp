#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        long long p, a, b, c;
        cin >> p >> a >> b >> c;

        if(p % a == 0 || p % b == 0 || p % c == 0){
            cout << "0\n";
            continue;
        }

        ll ans = min(a - p % a, min(b - p % b, c - p % c));
        cout << ans << "\n";
    }
}