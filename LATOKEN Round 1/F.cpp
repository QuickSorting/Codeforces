#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template<class T> void check_min(T &a, const T b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T b){ a = (a > b) ? a : b; }

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<string> s(n);
    for(int i = 0; i < n; ++i)
        cin >> s[i];

    vector<int> a(m);
    for(int i = 0; i < m; ++i)
        cin >> a[i];

    vector<int> mn(m, n);
    for(int j = 0; j < m; ++j){
        for(int i = 0; i < n; ++i)
            if(s[i][j] == '#'){
                mn[j] = i;
                break;
            }
    }

    set<pair<int, int>> _set;
    for(int j = 0; j < m; ++j)
        if(mn[j] != n)
            _set.insert({mn[j], j});

    int ans = 0;
    while(!_set.empty()){
        ++ans;
        auto [val, j] = *_set.begin();
        cout << val << " " << j << endl;

        stack<pair<int, int>> st;
        st.push({val, j});
        while(!st.empty()){
            auto [val, j] = st.top();
            cout << "stack " << val << " " << j << endl;
            st.pop();
            mn[j] = n;
            _set.erase({val, j});
            for(auto [x, y]: _set)
                cout << x << " ste " << y << endl;

            if(j && mn[j - 1] != n && mn[j - 1] >= val)
                st.push({mn[j - 1], j - 1});
            if(j != m - 1 && mn[j + 1] != n && mn[j + 1] >= val)
                st.push({mn[j + 1], j + 1});
        }
    }
    cout << ans << "\n";
}