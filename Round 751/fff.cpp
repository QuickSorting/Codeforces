#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }
#define all(x) (x).begin(), (x).end()

int f(int x){
    int ans = x;
    int mx = 0;
    while(x > 0){
        mx = max(mx, x % 10);
        x /= 10;
    }
    return ans * mx;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> v;
    int n = 1000000;
    for(int i = 1; i <= n; ++i)
        v.push_back(f(f(f(i))));
    sort(v.begin(), v.end());
    for(int i = 0; i < n; ++i){
        if(v[i] >= 125000000){
            cout << (i * 100 / (4 * n)) << "\n";
            return 0;
        }
    }
    cout << v[n * 1 / 4 - 1] << " " << v[n * 3 / 4 - 1] << "\n";
}