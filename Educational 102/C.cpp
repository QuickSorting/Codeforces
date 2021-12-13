#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        int n, k;
        cin >> n >> k;

        vector<int> v;
        for(int i = 1; i <= k - 1; ++i)
            v.push_back(i);
        v.insert(v.begin() + k - 1 - (n - k), k);

        for(int i = 0; i < k; ++i)
            cout << v[i] << " ";
        cout << "\n";
    }
}