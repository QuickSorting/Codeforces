#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }

const int N = 2e5 + 3;

int n, m, x;
int a[N], b[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> x;
    for(int i = 0; i < n; ++i) cin >> a[i];
    for(int i = 0; i < m; ++i) cin >> b[i];

    cout << " ";
    for(int i = 0; i < m; ++i)
        cout << b[i];
    cout << "\n";
    for(int i = 0; i < n; ++i){
        cout << a[i];
        for(int j = 0; j < m; ++j)
            cout << ((a[i] + b[j] > x) ? '#' : '.');
        cout << "\n";
    }
}