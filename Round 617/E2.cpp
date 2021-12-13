#include <bits/stdc++.h>

using namespace std;

const int kMaxN = 2e5 + 7;

int cnt[26];
int col[kMaxN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	string s;
	cin >> n >> s;

	for(int j = 0; j < 26; ++j)
		cnt[j] = 1;

	int ans = 1;
	for(int i = 0; i < n; ++i){
		int x = cnt[s[i] - 'a'];

		for(int j = s[i] - 'a' - 1; j >= 0; --j)
			cnt[j] = max(cnt[j], x + 1);
		col[i] = x;
		ans = max(ans, x);
	}

	cout << ans << "\n";
	for(int i = 0; i < n; ++i)
		cout << col[i] << " ";
	cout << "\n"; 
}