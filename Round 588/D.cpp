#include <bits/stdc++.h>

using namespace std;

const long long MAXN = 2e5 + 7;
const long long MAXK = 6;
const long long MAXP = 123;

long long n, k;
long long f;
long long op[MAXP][MAXP];
vector<long long> p[MAXN];
long long nxt[MAXN][MAXP], idx[MAXN];
bool used[MAXN];
long long cnt, ans = 0;

void init(){
	f = 1;
	for(long long i = 1; i <= (k - 1); ++i){
		f *= i;
	}

	for(long long i = 0; i < f; ++i){
		for(long long j = 0; j < f; ++j){
			op[i][j] = i ^ j;
		}
	}
}

long long get_idx(const vector<long long> &v){
	long long curr = f;
	long long ret = 0;
	long long arr[6];
	for(long long i = 1; i <= 5; ++i){
		arr[i] = i - 1;
	}

	for(long long i = 0; i < k; ++i){
		ret += arr[v[i]] * curr;
		for(long long j = v[i] + 1; j <= k; ++j){
			--arr[j];
		}

		if(i != k - 1){
			curr /= k - i - 1;
		}
 	}

 	return ret;
}





void add(int )

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;
	init();

	for(long long i = 0; i < n; ++i){
		for(long long j = 0; j < k; ++j){
			long long x;

			cin >> x;
			p[i].push_back(x);
		}
		//cout << get_idx(p[i]) << "\n";
		idx[i] = get_idx(p[i]);
	}

	for(long long j = 0; j < f; ++j){
		nxt[n][j] = n;
	}
	
	for(long long i = n - 1; i >= 0; --i){
		for(long long j = 0; j < f; ++j){
			nxt[i][j] = nxt[i + 1][j];
		}
		nxt[i][idx[i]] = i;
	}

	for(long long i = 0; i < n; ++i){
		for(long long j = 0; j < f; ++j){
			used[j] = false;
		}
		used[0] = true;
		cnt = 1;

		long long curr = i;
		while(true){
			long long mn = n;
			for(long long j = 0; j < f; ++j){
				if(!used[j]){
					mn = nxt[curr][j];
				}
			}
			
			ans += (mn - curr) * cnt;

			if(mn == n){
				break;
			}

			curr = mn;
			add(p[curr]);
		}
	}
}