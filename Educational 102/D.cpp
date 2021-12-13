#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        int n, m;
        cin >> n >> m;

        string s;
        cin >> s;

        vector<int> p(n + 2);
        p[0] = 0;
        for(int i = 1; i <= n; ++i)
            p[i] = p[i - 1] + (s[i - 1] == '+' ? 1 : -1);

        vector<int> mx_p(n + 2), mn_p(n + 2), mx_s(n + 2), mn_s(n + 2);
        mx_p[0] = mn_p[0] = 0;
        for(int i = 1; i <= n; ++i){
            mx_p[i] = max(p[i], mx_p[i - 1]);
            mn_p[i] = min(p[i], mn_p[i - 1]);
        }

        mx_s[n + 1] = INT_MIN;
        mn_s[n + 1] = INT_MAX;
        for(int i = n; i >= 1; --i){
            mx_s[i] = max(p[i], mx_s[i + 1]);
            mn_s[i] = min(p[i], mn_s[i + 1]);
        }

        for(int i = 0; i < m; ++i){
            int l, r;
            cin >> l >> r;

            pair<int, int> range_1, range_2;
            range_1 = {mn_p[l - 1], mx_p[l - 1]};

            if(r == n) range_2 = {0, 0};
            else{
                range_2 = {mn_s[r + 1], mx_s[r + 1]};
                range_2.first += p[l - 1] - p[r];
                range_2.second += p[l - 1] - p[r];
            }

            //cout << range_1.first << " " << range_1.second << " range_1\n";
            //cout << range_2.first << " " << range_2.second << " range_2\n";

            if(range_1.first > range_2.first)
                swap(range_1, range_2);
            if(range_1.second < range_2.first)
                cout << range_1.second - range_1.first + range_2.second - range_2.first + 2 << "\n";
            else
                cout << max(range_2.second, range_1.second) - range_1.first + 1 << "\n";
        }
    }
}