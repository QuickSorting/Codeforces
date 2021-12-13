#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 1e5 + 3;

vector<array<int, 3>> ans;
int a[N];

void solve(int n){
    for(int i = 1; i <= n - 2; i += 2)
        ans.push_back({i, i + 1, i + 2});
    for(int i = n - 4; i >= 1; i -= 2)
        ans.push_back({i, i + 1, i + 2});
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for(int i = 0; i < n; ++i)
        cin >> a[i];

    if(n % 2 == 0){
        int x = 0;
        for(int i = 0; i < n; ++i)
            x ^= a[i];
        if(x){
            cout << "NO\n";
            return 0;
        }
            
        solve(n - 1);
    }
    else solve(n);

    cout << "YES\n";
    cout << ans.size() << "\n";
    for(int i = 0; i < ans.size(); ++i)
        cout << ans[i][0] << " " << ans[i][1] << " " << ans[i][2] << "\n";

    return 0;
}