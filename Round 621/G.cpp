#include <bits/stdc++.h>

using namespace std;

const int kMaxN = 51;
const int kMaxQ = 1e5 + 7;
const int kMaxW = 1e6 + 7;
const int kInf = 1e9;

int n, m;
int dist[kMaxN][kMaxN];
bool to_one[kMaxN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j){
			if(i != j)
				dist[i][j] = kInf;
		}
	}

	for(int i = 0; i < m; ++i){
		int u, v, w;
		cin >> u >> v >> w;

		dist[u][v] = w;
		if(u == 1)
			to_one[v] = true;
	}

	for(int k = 1; k <= n; ++k)
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= n; ++j)
				if(dist[i][j] > dist[i][k] + dist[k][j])
					dist[i][j] = dist[i][k] + dist[k][j];

	vector<long long> v;
	for(int i = 2; i <= n; ++i)
		if(to_one[i] && dist[i][n] != kInf)
			v.push_back(dist[1][i] + dist[i][n]);

	sort(v.begin(), v.end());

	int q;
	cin >> q;

	for(int i = 0; i < q; ++i){
		int x;
		cin >> x;

		long long sum = 0;
		long long j = 0;
		for(; j < v.size(); ++j){
			if(v[j] * j - sum > x)
				break;
			sum += v[j];
		}
		--j;
		x -= v[j] * (j + 1) - sum;
		long double ans = v[j];
		ans += ((long double)x / (long double)(j + 1));

		cout << fixed << setprecision(12) << ans << "\n";
	}
}