#include <bits/stdc++.h>

using namespace std;

const int kMaxN = 407;

pair<int, bool> dp[kMaxN][kMaxN];
string s, t;

int solve(int l, int r){
	if(dp[l][r].second)
		return dp[l][r].first;

	dp[l][r].second = true;
}

void solve(){
	
	cin >> s >> t;
	srand(time(NULL));

	for(int i = 0; i < t.size(); ++i){
		for(int j = 0; j <= i; ++j){
			for(int k = i + 1)
		}
	}

	cout << "NO\n";
	return;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	while(t--)
		solve();
}