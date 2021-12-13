#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 2e5 + 3;
const int C = 200;

int n, cnt[N], a[N], mn[2 * N], ans; 
vector<int> pos[N];

void solve_big(int x){
    mn[N] = 0;

    int diff = N;
    for(int i = 1; i <= n; ++i){
        if(a[i] == mx_el) diff++;
        else if(a[i] == x) diff--;

        if(diff == N) ans = max(ans, i);
        else{
            if(mn[diff]) ans = max(ans, i - mn[diff]);
            else mn[diff] = i;
        }
    }

    fill(mn, mn + 2 * N, 0);
}

void solve_small(int x){
    for(int i = 0; i < pos[x].size(); ++i){
        int j = lower_bound(pos[mx_el].begin(), pos[mx_el].end(), pos[x][i]) - pos[mx_el].begin();

        int diff = N;
        vector<int> to_remove;
        mn[diff] = 0;

        for(int k = i; k < pos[x].size(); ++k){
            
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int mx = 0, cnt_mx = 0, mx_el;

    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        cnt[a[i]]++;
        if(cnt[a[i]] > mx){
            mx = cnt[a[i]];
            cnt_mx = 1;
            mx_el = a[i];
        }
        else if(cnt[a[i]] == mx)
            cnt_mx++;
        pos[a[i]].push_back(i);
    }

    if(cnt_mx > 1){
        cout << n << '\n';
        return 0;
    }

    for(int i = 1; i <= n; ++i){
        if(i == mx_el) continue;
        if(pos[i].size() > C) solve_big(i);
        else solve_small(i);
    }

    cout << ans << "\n";
}