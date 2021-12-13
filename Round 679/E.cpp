#include <bits/stdc++.h>

using namespace std;

map<pair<int, int>, int> dp;
int n;

int v[100000];

int get_mex(const vector<int> &nums){
    int pr = -1;
    for(int i = 0; i < nums.size(); ++i){
        if(nums[i] == pr) continue;
        if(nums[i] != pr + 1) return pr + 1;
        pr++;
    }
    return pr + 1;
}

int solve(int pos, int sum){
    if(sum > v[n])
        return 0;
    if(dp.count({pos, sum}))
        return dp[{pos, sum}];

    int &ans = dp[{pos, sum}];
    vector<int> moves;

    for(int i = pos + 1; i <= n; ++i){
        if(v[i] < sum) continue;
        moves.push_back(solve(i, 2 * v[i] - v[pos] + 1));
    }

    sort(moves.begin(), moves.end());
    int mex = get_mex(moves);

    ans = mex;
    cout << "solve(" << pos << "," << sum << ") = " << ans << "\n";
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for(int i = 1; i <= n; ++i)
        cin >> v[i];

    vector<int> ans;
    for(int i = 1; i <= n; ++i)
        ans.push_back(solve(i, -1));

    sort(ans.begin(), ans.end());
    cout << get_mex(ans) << " mex\n"; 
}