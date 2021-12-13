#include <bits/stdc++.h>

using namespace std;

const int k_N = 5000 + 3;
const int k_Inf = 1e9 + 3;

int a[k_N];
vector<pair<int, int>> v;
map<int, int> cnt;

int solve(int l, int r){
    if(l > r) return 0;

    int mn = k_Inf;
    for(int i = l; i <= r; ++i)
        mn = min(mn, v[i].second);

    int ans = mn, pr = l;

    for(int i = l; i <= r; ++i)
        v[i].second -= mn;

    for(int i = l; i <= r; ++i){
        if(v[i].second != 0){
            int j;
            for(j = i + 1; j <= r; ++j)
                if(v[j].second == 0) break;
            j--;

            ans += solve(i, j);
            i = j;
        }
    }

    ans = min(ans, r - l + 1);
    //cout << "solve(" << l << ", " << r << ") = " << ans << endl;
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for(int i = 0; i < n; ++i){
        int x;
        cin >> x;
        v.push_back({i + 1, x});
    }

    int ans = 0, pr = 0;
    ans = solve(0, v.size() - 1);

    cout << ans << "\n";
}