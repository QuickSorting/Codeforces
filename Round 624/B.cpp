#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n, m;
	cin >> n >> m;

	vector<int> a(n + 1);
	vector<bool> can(n + 1, false);
	for(int i = 1; i <= n; ++i)
		cin >> a[i];

	vector<int> p(m + 1);
	for(int i = 1; i <= m; ++i){
		cin >> p[i];
		can[p[i]] = true;
	}

	for(int i = 1; i < n; ++i){
		int mx = a[1];
		for(int j = 1; j <= i; ++j)
			mx = max(mx, a[j]);

		int mn = a[n];
		for(int j = n; j > i; --j)
			mn = min(mn, a[j]);

		if(!can[i] && mx > mn){
			cout << "NO\n";
			return;
		}
	}

	cout << "YES\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	while(t--)
		solve();
}