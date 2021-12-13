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
        cin >> n;

        vector<int> a(n);
        for(int i = 0; i < n; ++i)
            cin >> a[i];

        int t = (1 << 30) - 1;
        for(int i = 0; i < n; ++i)
            t &= a[i];
        cout << t << "\n";
    }
}