#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        long long x, y, z;
        cin >> x >> y >> z;
        cout << max(z - x, z - y) << "\n";
    }
}