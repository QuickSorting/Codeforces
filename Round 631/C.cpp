#include <bits/stdc++.h>

using namespace std;

const int kN = (1 << 20) + 1;

int a[kN];

void solve(){
	int h, g;
	cin >> h >> g;

	int n = (1 << h) - 1;
	for(int i = 1; i <= h; ++i)
		cin >> a[i];

	for(int cnt = 0; cnt < h - g; ++cnt){
		
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