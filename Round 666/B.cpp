#include <bits/stdc++.h>

using namespace std;

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

        sort(a.begin(), a.end());



        if(a[n - 1] == 1){
            cout << ((n & 1) ? "T" : "HL") << "\n";
            continue;
        }

        long long sum = 0;
        for(int i = 0; i < n; ++i)
            sum += a[i];

        cout << ((sum & 1) ? "HL" : "T") << "\n";
    }
}