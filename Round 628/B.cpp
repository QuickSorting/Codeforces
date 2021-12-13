#include <bits/stdc++.h>

using namespace std;

const int kN = 2e5 + 7;

int a[kN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	while(t--){
		int n;
		cin >> n;

		for(int i = 0; i < n; ++i)
			cin >> a[i];

		sort(a, a + n);

		int ans = n;
		for(int i = 0; i < n - 1; ++i)
			ans -= (a[i] == a[i + 1]);

		cout << ans << "\n";
	}
}