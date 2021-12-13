#include <bits/stdc++.h>

using namespace std;

const int MAXN = 207;
const long long mod = 998244353;

string s;
pair<long long, bool> dp[MAXN][MAXN][MAXN];

long long solve(int pos, int depth, int max_depth){
	max_depth = max(depth, max_depth);
	if(pos == (int)s.size()){
		return max_depth;
	}
	bool &calc = dp[pos][depth][max_depth];
	long long &d = dp[pos][depth][max_depth].first;
	if(calc)
		return d;

	calc = true;
	d = 0;

	if(s[pos] == '('){
		d = solve(pos + 1, depth + 1, max_depth);
		return d;
	}
	if(s[pos] == ')'){
		
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> s;

	cout << solve(0, 0) << "\n";
	return 0;
}