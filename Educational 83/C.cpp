#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long t;
	cin >> t;

	while(t--){
		long long n, k;
		cin >> n >> k;

		vector<long long> a(n);
		for(long long i = 0; i < n; ++i)
			cin >> a[i];

		vector<long long> bits(63, 0);
		bool ok = true;
		for(long long i = 0; i < n; ++i){
			for(long long j = 0; j < 63; ++j){
				if(a[i] % k == 0){
					a[i] /= k;
					continue;
				}

				if(a[i] % k != 1){
					ok = false;
					break;
				}

				a[i] /= k;

				bits[j]++;
				if(bits[j] > 1){
					ok = false;
					break;
				}
			}
		}

		cout << (ok ? "YES" : "NO") << "\n";
	}
}