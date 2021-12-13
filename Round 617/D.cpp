#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, a, b, k;
	cin >> n >> a >> b >> k;

	vector<int> h(n);
	for(int i = 0; i < n; ++i)
		cin >> h[i];

	vector<int> cnt(n);
	for(int i = 0; i < n; ++i){
		if(h[i] % (a + b) == 0){
			cnt[i] = b / a + (bool)(b % a);
			continue;
		}

		int x = h[i] % (a + b);
		cnt[i] = x / a + (bool)(x % a) - 1;
		cnt[i] = max(cnt[i], 0);
	}

	sort(cnt.begin(), cnt.end());
	int ans = 0;
	for(int i = 0; i < n; ++i){
		if(cnt[i] <= k){
			k -= cnt[i];
			++ans;
		}
	}

	cout << ans << "\n";
}