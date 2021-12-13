#include <bits/stdc++.h>

using namespace std;

const long long mod = 1e9 +  7;

void solve(){
	long long x;
	string s;
	string c = "";

	cin >> x >> s;

	int l = 0;
	while(s.size() < x){
		++l;
		c = "";
		for(int i = l; i < s.size(); ++i){
			c += s[i];
		}

		int curr = s[l - 1] - '0';
		for(int i = 0; i < curr - 1; ++i){
			s += c;
		}
	}

	//cout << s << " " << c << endl;

	long long ans = (int)s.size(), c_len = (int)c.size();
	while(l != x){
		++l;

		int curr = s[l - 1] - '0';
		c_len = ans - l + mod;
		c_len %= mod;
		ans = l + (curr * c_len % mod);
		ans %= mod;
	}

	cout << ans << "\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	while(t--){
		solve();
	}
}