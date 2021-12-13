#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        int n, m;
        cin >> n >> m;

        vector<int> a(n), x(m);
        for(int &val: a) cin >> val;
        for(int &val: x) cin >> val;

        ll sum = 0;
        vector<pair<ll, int>> v;
        for(int i = 0; i < n; ++i){
            sum += a[i];
            if(sum > 0 && (v.empty() || sum > v.back().first))
                v.push_back({sum, i});
        }

        if(v.empty()){
            for(int i = 0; i < m; ++i)
                cout << "-1 ";
            cout << "\n";
            continue;
        }

        pair<ll, int> mx = v.back();

        for(int i = 0; i < m; ++i){
            if(sum <= 0){
                auto it = lower_bound(v.begin(), v.end(), pair<ll, int>{x[i], -1});
                if(it == v.end()) cout << "-1 ";
                else cout << it->second << " ";
            }
            else{
                ll ans = 0;
                x[i] -= mx.first;
                if(x[i] >= 0){
                    ll d = (ll)((x[i] / sum) + !!(x[i] % sum));
                    ans +=  d * n;
                    x[i] -= d * sum;
                    x[i] += mx.first;
                }
                else x[i] += mx.first;

                if(x[i] < 0){
                    cout << ans - 1 << " ";
                    continue;
                }

                auto it = lower_bound(v.begin(), v.end(), pair<ll, int>{x[i], -1});
                ans += it->second;
                cout << ans << " ";
            }
        }
        cout << "\n";
    }
}