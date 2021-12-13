#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n, d;
	cin >> n >> d;

	for(int i = 1; i <= n; ++i){
		int n2 = n - i;
		int d2 = d - i * (i + 1) / 2;
		if(d2 < 0)
			break;

		for(int i = 1; i <= n; ++i){
			
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	while(t--)
		solve();
}