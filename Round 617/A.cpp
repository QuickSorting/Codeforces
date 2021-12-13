#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n;
	cin >> n;

	vector<int> a(n);
	int sum = 0;
	bool odd = false, even = false;
	for(int i = 0; i < n; ++i){
		cin >> a[i];
		sum += a[i];

		if(a[i] & 1)
			odd = true;
		else
			even = true;
	}

	if(sum & 1 || (odd && even))
		cout << "YES\n";
	else
		cout << "NO\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	while(t--)
		solve();
}