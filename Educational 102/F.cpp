#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 3e3 + 3;
const int T = 100 + 3;

int n, a[N], b[N];
int sum[T];
bool v[T][T], vis[T];
int np[N];
int ans = 0;

void solve(int pos, int curr){
    if(pos > 50){
        ans = max(ans, curr);
        return;
    }
    if(np[pos]){
        solve(pos + 1, curr);
        return;
    }
    if(sum[pos] >= 0){
        solve(pos + 1, curr + sum[pos]);
        return;
    }

    if(pos > 33){
        int add = sum[pos];
        if(!np[2 * pos]) add += max(sum[2 * pos], 0);
        solve(pos + 1, curr + max(add, 0));
        return;
    }

    solve(pos + 1, curr + sum[pos]);

    for(int i = 2; i * pos <= 100; ++i)
        np[i] += v[pos][i];

    solve(pos + 1, curr);

    for(int i = 2; i * pos <= 100; ++i)
        np[i] -= v[pos][i];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    for(int i = 0; i < n; ++i)
        cin >> b[i];

    for(int i = n - 1; i >= 0; --i){
        for(int j = 2; j * a[i] <= 100; ++j)
            if(vis[j * a[i]])
                v[a[i]][j] = true;
        sum[a[i]] += b[i];
    }

    solve(2, sum[1]);

    cout << ans;
}