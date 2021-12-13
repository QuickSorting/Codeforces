#include <bits/stdc++.h>

using namespace std;

const long long mod = 998244353;
const long long MAXN = 3e5 + 7;

long long n, k;
long long a[MAXN], b[MAXN];
pair<long long, bool> dp[4 * MAXN][2];
long long quer[MAXN], ans[MAXN];

void read(){
	cin >> n >> k;

	for(int i = 0; i < n; ++i){
		long long x;

		cin >> x;
		++a[x];
	}
	for(int i = 0; i < k; ++i){
		cin >> b[i];
	}
}

void solve(){
	int q;
	cin >> q;

	for(int i = 0; i < q; ++i){
		cin >> quer[i];
	}
	
	//sort(a, a + n);
	sort(b, b + k);

	for(int i = 0; i < k; ++i){
		long long cnt1 = 0, cnt2 = 0;
		for(int j = 0; j < MAXN; ++j){
			if(a[j] >= b[i]){
				continue;
			}

			if(a[j] == 1){
				++cnt1;
			}
			if(a[j] >= 2){
				++cnt2;
			}
		}

		for(int i = 0; i < q; ++i){
			long long curr = 0;
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	read();
	solve();

	return 0;
}