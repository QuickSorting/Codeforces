#include <bits/stdc++.h>

using namespace std;

void solve(){
	long long n, m;
	cin >> n >> m;

	string s;
	cin >> s;

	vector<long long> p(m);
	vector<long long> cnt(n);
	for(long long i = 0; i < m; ++i){
		cin >> p[i];
		if(p[i])
			++cnt[p[i] - 1];
	}
	++cnt[n - 1];

	for(long long i = n - 2; i >= 0; --i)
		cnt[i] += cnt[i + 1];

	vector<long long> ans(26);
	for(long long i = 0; i < n; ++i){
		ans[s[i] - 'a'] += cnt[i];
	}

	for(int i = 0; i < 26; ++i)
		cout << ans[i] << " ";
	cout << "\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long t;
	cin >> t;

	while(t--)
		solve();
}