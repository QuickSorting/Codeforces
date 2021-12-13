#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<pair<int, int>> ans;
    vector<int> s2, s3;
    for(int i = 1; i <= n; ++i){
        int a;
        cin >> a;

        if(a == 0) continue;
        if(a == 1){
            if(!s2.empty()){
                ans.push_back({s2.back(), i});
                s2.pop_back();
            }
            else if(!s3.empty()){
                ans.push_back({i, i});
                ans.push_back({s3.back(), i});
                s3.pop_back();
            }
            else ans.push_back({i, i});
            continue;
        }
        if(a == 2){
            ans.push_back({i, i});
            s2.push_back(i);
        }
        if(a == 3){
            ans.push_back({i, i});
            s3.push_back(i);
        }
    }

    if(!s2.empty() || !s3.empty()){
        cout << "-1\n";
        return 0;
    }

    cout << ans.size() << "\n";
    for(auto [x, y]: ans)
        cout << x << " " << y << "\n";
}