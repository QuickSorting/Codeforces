#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }
#define all(x) (x).begin(), (x).end()

const int N = 2e5 + 3;

int a[N], n;

void solve(){
    vector<int> ans;

    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];

    bool ok = true;
    while(ok){
        ok = false;
        for(int i = 1; i <= n - 2; ++i)
            if(a[i] + a[i + 1] + a[i + 2] == 2){
                ok = true;
                a[i] = a[i + 1] = a[i + 2] = 0;
                ans.push_back(i);
            }
        for(int i = n - 2; i >= 1; --i)
            if(a[i] + a[i + 1] + a[i + 2] == 2){
                ok = true;
                a[i] = a[i + 1] = a[i + 2] = 0;
                ans.push_back(i);
            }
    }

    for(int i = 1; i <= n; ++i)
        if(a[i]){
            cout << "NO\n";
            return;
        }

    cout << "YES\n";
    cout << ans.size() << "\n";
    for(int x: ans)
        cout << x << " ";
    cout << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    for(int i = 1; i <= t; ++i)
        solve();
}
