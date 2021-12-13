#include <bits/stdc++.h>

using namespace std;

int get_mex(const vector<int> &nums){
    int pr = -1;
    for(int i = 0; i < nums.size(); ++i){
        if(nums[i] == pr) continue;
        if(nums[i] != pr + 1) return pr + 1;
        pr++;
    }
    return pr + 1;
}

int get_ans(const vector<int> &v, int i, int m){
    int prev = 0, ans = 0;
    while(true){
        int l = i + 1, r = m;
        while(l != r){
            int mid = (l + r) >> 1;
            if(v[mid] - v[i] > prev) r = mid;
            else l = mid + 1;
        }

        if(r == m) break;
        ans++;
        prev = v[l] - v[i];
        i = l;
    }

    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int xor_num = 0;
    for(int i = 0; i < n; ++i){
        int m;
        cin >> m;

        vector<int> v(m);
        for(int i = 0; i < m; ++i)
            cin >> v[i];

        if(m == 1){
            xor_num ^= 1;
            continue;
        }

        vector<int> ans;
        for(int i = 0; i < m; ++i){
            ans.push_back(get_ans(v, i, m));
            cout << ans.back() << " ans.back()\n";
        }
        sort(ans.begin(), ans.end());

        xor_num ^= get_mex(ans);
        cout << "\n";
    }

    if(!xor_num) cout << "NO\n";
    else cout << "YES\n";
}