#include <bits/stdc++.h>

using namespace std;

const int k_N = 3000 + 3;

int a[k_N];
vector<int> idx[k_N];
int prefix[k_N][k_N];

int get_cnt(int i, int l, int r){
    if(l == 0) return prefix[i][r];
    return prefix[i][r] - prefix[i][l - 1];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        for(int i = 1; i <= n; ++i)
            cin >> a[i];

        for(int i = 1; i <= n; ++i){
            idx[i].clear();
            for(int j = 1; j <= n + 1; ++j)
                prefix[i][j] = 0;
        }

        for(int i = 1; i <= n; ++i){
            prefix[a[i]][i]++;
            idx[a[i]].push_back(i);
        }
        for(int i = 1; i <= n; ++i)
            idx[i].push_back(n + 1);

        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= n + 1; ++j)
                prefix[i][j] += prefix[i][j - 1];

        long long ans = 0;
        for(int i = 1; i <= n; ++i){
            for(int k = 1; k <= n; ++k){
                if(k == i) continue;
                long long sum = 0;
                for(int j = (int)idx[i].size() - 2; j >= 0; --j){
                    ans += sum * get_cnt(k, idx[i][j], idx[i][j + 1]) * (j + 1);
                    sum += get_cnt(k, idx[i][j], n);
                }
            }
            //cout << ans << endl;
            long long sz = idx[i].size() - 1;
            ans += sz * (sz - 1) * (sz - 2) * (sz - 3) / (4 * 3 * 2 * 1);
        }

        cout << ans << "\n";
    }
}