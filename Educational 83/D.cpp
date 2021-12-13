#include <bits/stdc++.h>

using namespace std;

const long long mod = 998244353;
const int kN = 2e5 + 7;

long long fpow(long long base, long long exp){
	if(!exp)
		return 1ll;

	if(exp & 1)
		return base * fpow(base, exp - 1) % mod;

	long long t = fpow(base, exp >> 1);
	return t * t % mod;
}

long long inverse(long long x){
	return fpow(x, mod - 2);
}

long long f[kN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	if(n == 2){
		cout << "0\n";
		return 0;
	}

	f[0] = 1;
	for(int i = 1; i < kN; ++i)
		f[i] = i * f[i - 1] % mod;

	long long ans = 0;
	for(int t = m; t >= 1; --t){
		if(t - 2 < n - 3)
			break;

		ans += f[t - 2] * inverse(f[n - 3]) % mod * inverse(f[t - n + 1]) % mod * (t - 1) % mod * fpow(2, n - 3) % mod;
		ans %= mod;
	}

	cout << ans << "\n";
}