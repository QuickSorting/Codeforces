#include <bits/stdc++.h>

using namespace std;

mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
int rand(int l, int r){
	return mt() % (r - l + 1) + l;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n = rand(3, 5);
	cout << n << "\n";

	for(int i = 0; i < n; ++i){
		cout << rand(-5, 5) << " " << rand(-5, 5) << "\n";
	}
}