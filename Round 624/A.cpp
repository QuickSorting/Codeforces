#include <bits/stdc++.h>

using namespace std;

void solve(){
	int a, b;
	cin >> a >> b;

	if(a == b)
		cout << "0\n";
	else if((b > a && (b - a) & 1) || (a > b && (b - a) % 2 == 0))
		cout << "1\n";
	else
		cout << "2\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	while(t--)
		solve();
}