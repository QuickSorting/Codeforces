#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n;
	string s;
	cin >> n >> s;

	map<pair<int, int>, int> mp;
	pair<int, int> c(0, 0);
	int ans = -1, l, r;
	mp[c] = -1;
	for(int i = 0; i < n; ++i){
		switch(s[i]){
		case 'L':
			c.first++;
			break;
		case 'R':
			c.first--;
			break;
		case 'U':
			c.second++;
			break;
		case 'D':
			c.second--;
			break;
		}

		if(mp.count(c)){
			if(i - mp[c] < ans || ans == -1){
				ans = i - mp[c];
				l = mp[c];
				r = i;
			}
		}
		mp[c] = i;
	}

	if(ans == -1){
		cout << "-1\n";
		return;
	}

	cout << l + 2 << " " << r + 1 << "\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	while(t--)
		solve();
}