#include <bits/stdc++.h>

using namespace std;

void solve(){
	int s;
	cin >> s;

	int ans = 0;
	while(s >= 10){
		int t = s / 10;
		s %= 10;
		s += t;
		ans += t  * 10;
	}
	ans += s;

	cout << ans << "\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	while(t--)
		solve();
}