#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }
#define all(x) (x).begin(), (x).end()

const int N = 1e6 + 3;

int n, m, a[N], b[N];
set<vector<bool>> vis;

void find_all(int a_idx, int b_idx, const vector<bool> &curr){
    if(b_idx == m + 1){
        if(vis.count(curr)) return;
        vis.insert(curr);
        return;
    }
    if(a_idx + b[b_idx] - 1 > n){
        find_all(1, b_idx + 1, curr);
        return;
    }

    vector<bool> new_curr = curr;
    for(int i = a_idx; i <= a_idx + b[b_idx] - 1; ++i)
        new_curr[i] = !new_curr[i];
    find_all(a_idx + 1, b_idx, new_curr);
    find_all(a_idx + 1, b_idx, curr);
}

void solve(){
    cin >> n >> m;
    // for(int i = 1; i <= n; ++i)
        // cin >> a[i];
    for(int i = 1; i <= m; ++i)
        cin >> b[i];

    vector<bool> curr(1 + n, false);
    find_all(1, 1, curr);

    cout << vis.size() << endl;
    for(auto curr: vis){
        for(int i = 1; i <= n; ++i)
            cout << curr[i] << " ";
        cout << endl;
    }
    vis.clear();
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--)
        solve();
}