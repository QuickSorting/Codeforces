#include <bits/stdc++.h>

using namespace std;

const int MAXN = 53;

int n, m;
vector<pair<int, int> > edges;
bool matrix[MAXN][MAXN];
int res[MAXN];

void solve(){
	for(auto edge: edges){
		++res[edge.first];
		--res[edge.second];
		matrix[edge.first][edge.second] = true;
	}

	while(true){
		int mx_diff = -1, u = -1, v = -1;
		for(int i = 0; i < n; ++i){
			for(int j = i + 1; j < n; ++j){
				if(matrix[i][j] || matrix[j][i])
					continue;

				int curr = abs(res[i] - res[j]);
				if(curr > mx_diff){
					mx_diff = curr;
					u = i;
					v = j;
				}
			}
		}

		if(u == -1)
			break;
		if(res[u] < res[v])
			swap(u, v);

		--res[u];
		++res[v];
		matrix[v][u] = true;
	}

	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			cout << matrix[i][j];
		}
		cout << "\n";
	}
}

void read(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for(int i = 0; i < m; ++i){
		int u, v;
		cin >> u >> v;
		--u;
		--v;

		edges.push_back({u, v});
	}
}

int main(){
	read();
	solve();
}