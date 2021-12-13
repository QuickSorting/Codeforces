#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long u, v;
	cin >> u >> v;

	if(u == 0 && v == 0){
		cout << "0\n";
		return 0;
	}
	if(u > v){
		cout << "-1\n";
		return 0;
	}
	if((u & 1) != (v & 1)){
		cout << "-1\n";
		return 0;
	}

	array<long long, 3> arr{0, 0, 0};
	int n = 1;
	arr[0] = u;

	long long diff = v - u;
	for(long long bit = 1; bit < 63; ++bit){
		if((1ll << bit) & diff){
			n = max(n, 2);
			if(arr[0] & (1ll << (bit - 1))){
				n = 3;
				arr[1] += (1ll << (bit - 1));
				arr[2] += (1ll << (bit - 1));
			}
			else{
				arr[0] += (1ll << (bit - 1));
				arr[1] += (1ll << (bit - 1));
			}
		}
	}

	cout << n << "\n";
	for(int i = 0; i < n; ++i)
		cout << arr[i] << " ";
	cout << "\n";
}