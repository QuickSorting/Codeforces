#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    int imp = n / 2;
    
    vector<int> a(n, k);
    for(int t = 0; t < 100; ++t){
        for(int i = 0; i < n; ++i){
            cout << a[i] << " ";
        }
        cout << "\n";

        vector<int> b(n, 0);
        for(int i = 0; i < n; ++i){
            int prev_idx = (i + n - 1) % n;
            int prev = a[prev_idx];
            int nxt_idx = (i + 1) % n;
            int nxt = a[nxt_idx];
            if(prev_idx != imp) prev = prev / 2 + prev % 2;
            if(nxt_idx != imp) nxt = nxt / 2;
            else nxt = 0;       
            b[i] = prev + nxt;
        }
        swap(a, b);
    }
}