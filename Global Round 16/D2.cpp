#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }
#define all(x) (x).begin(), (x).end()  

const int N = 300 + 3;

int n, m, c[N * N];
array<int, 2> a[N * N];
bool b[N * N];

struct Fenwick{
    int a[N * N];

    void update(int i, int v){
        for(++i; i < N * N; i += i & -i)
            a[i] += v;
    }
    int query(int i){
        int ret = 0;
        for(++i; i >= 1; i -= i & -i)
            ret += a[i];
        return ret;
    }
} f;

void solve(){
    cin >> n >> m;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j){
            cin >> a[i * m + j][0];
            a[i * m + j][1] = i * m + j;
        }
    sort(a, a + n * m, [](auto l, auto r){
        if(l[0] == r[0]){
            if(l[1] / m == r[1] / m)
                return l[1] < r[1];
            return l[1] > r[1];
        }
        return l[0] < r[0];
    });

    fill(b, b + n * m, false);
    for(int i = 0; i < n * m; ++i)
        c[a[i][1]] = i;

    ll ans = 0;
    for(int i = 0; i < n * m; ++i){
        for(int j = 0; j < c[i]; ++j)
            ans += b[j];
        b[c[i]] = true;
    }
    cout << ans << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    for(int i = 1; i <= t; ++i)
        solve();
}