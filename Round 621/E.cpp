#include <bits/stdc++.h>

using namespace std;

const int kMaxN = 5007;
const long long kMod = 1e9 + 7;

int s[kMaxN];
vector<int> h[kMaxN];

pair<long long, long long> dp[kMaxN][kMaxN];
int l[kMaxN][kMaxN], r[kMaxN][kMaxN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	for(int i = 0; i < n; ++i)
		cin >> s[i];

	for(int i = 0; i < m; ++i){
		int f;
		cin >> f;

		int hunger;
		cin >> hunger;
		h[f].push_back(hunger);
	}

	for(int i = 1; i <= n; ++i){
		l[i][0] = 0;
		for(int j = 1; j <= n; ++j)
			l[i][j] = l[i][j - 1] + (s[j] == i);

		r[i][n + 1] = 0;
		for(int j = n + 1; j >= 1; --j)
			r[i][j] = r[i][j + 1] + (s[j] == i);
	}

	for(int i = 1; i <= n; ++i)
		sort(h[i].begin(), h[i].end());

	for(int i = 0; i <= n; ++i){
		for(int j = 1; j <= n; ++j){
			if(h[j].empty())
				continue;

			dp[i][j].first = 0;
			if(h[j][0] <= l[j][i] || h[j][0] <= r[j][i + 1])
				dp[i][j].first = 1;
			if(h[j].size() >= 2){
				pair<int, int> p1 = {h[j][0], h[j][1]};
				pair<int, int> p2 = {l[j][1], r[j][i + 1]};
				if(p2.first > p2.second)
					swap(p2.first, p2.second);

				if(p1.first <= p2.first && p1.second <= p2.second)
					dp[i][j].first = 2;
			}

			if(dp[i][j].first == 0){
				dp[i][j].second = 1;
				continue;
			}
			if(dp[i][j].first == 1){
				if(h[j][0] <= l[j][i] && h[j][0] <= r[j][i + 1])
					dp[i][j].second = 2;
				else
					dp[i][j].second = 1;
				continue;
			}

			pair<int, int> p2 = {l[j][1], r[j][i + 1]};
			if(p2.first > p2.second)
				swap(p2.first, p2.second);

			auto it1 = h[i].lower_bound(p2.first);
			auto it2 = h[i].lower_bound(p2.second);

			long long cnt1 = h[i].end() - it1, cnt2 = h[i].end() - it2;
			dp[i][j] = 
		}
	}
}