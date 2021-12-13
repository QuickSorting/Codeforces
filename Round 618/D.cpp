#include <bits/stdc++.h>

using namespace std;

const int kMaxN = 1e5 + 7;
const int kMaxWeight = 32;
const long long kMod = 1e9 + 7;

bool used[kMaxN], d1[kMaxN];
int weight[kMaxN], w1[kMaxN];
bool possible[kMaxN][kMaxWeight];
vector<pair<int, int>> adj[kMaxN];

void dfs_d1(int u, int par, int root){
	used[u] = true;

	for(pair<int, int> edge: adj[u]){
		int to = edge.first;
		int w = edge.second;

		if(to == par || (d1[to] && to != root))
			continue;
		if(used[to]){
			possible[root][(weight[u] ^ weight[to] ^ w)] = true;
			continue;
		}

		weight[to] = weight[u] ^ w;
		dfs_d1(to, u, root);
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	for(int i = 0; i < m; ++i){
		int u, v, w;
		cin >> u >> v >> w;

		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}

	for(pair<int, int> edge: adj[1]){
		int u = edge.first;
		d1[u] = true;
		w1[u] = edge.second;
	}

	for(pair<int, int> edge: adj[1]){
		int u = edge.first;
		dfs_d1(u, 1, u);

		vector<int> to_try;
		for(int i = 1; i < kMaxWeight; ++i){
			if(possible[u][i])
				to_try.push_back(i);
		}
		
		for(int x: to_try){
			for(int i = 0; i < kMaxWeight; ++i){
				if(i == x)
					continue;
				if(possible[u][i] && !possible[u][(i ^ x)]){
					possible[u][(i ^ x)] = true;
					to_try.push_back(i ^ x);
				}
			}
		}

		/*for(int i = 0; i < kMaxWeight; ++i){
			cout << possible[u][i] << " " << u << " " << i << " = possible[u][i] u i\n";
		}*/
	}

	long long ans = 1;
	for(pair<int, int> edge: adj[1]){
		int u = edge.first;
		int buddy = -1, buddy_w;
		for(pair<int, int> edge2: adj[u]){
			int to = edge2.first;
			if(d1[to]){
				buddy = to;
				buddy_w = edge2.second;
				break;
			}
		}

		if(buddy == -1){
			if(!possible[u][0]){
				ans *= 2;
				ans %= kMod;
			}
			continue;
		}
		if(u < buddy)
			continue;

		bool cycle_together = false;
		for(int i = 0; i < kMaxWeight; ++i){
			int curr = i ^ w1[u] ^ w1[buddy] ^ buddy_w;
			if((possible[u][i] || i == 0) && (possible[buddy][curr] || curr == 0))
				cycle_together = true;
		}

		int cnt = 0;
		for(int i = 0; i < kMaxWeight; ++i){
			if(possible[buddy][0]){
				++cnt;
				break;
			}
			if(possible[u][i] && (possible[buddy][i] || i == 0)){
				++cnt;
				break;
			}
		}
		for(int i = 0; i < kMaxWeight; ++i){
			if(possible[u][0]){
				++cnt;
				break;
			}
			if((possible[u][i] || i == 0) && possible[buddy][i]){
				++cnt;
				break;
			}
		}

		if(!cycle_together){
			ans *= 4 / (1 << cnt);
			ans %= kMod;
			continue;
		}

		if(cnt == 0){
			ans *= 3;
			ans %= kMod;
			continue;
		}

		ans *= 4 / (1 << cnt);
		ans %= kMod;
		continue;
	}

	cout << ans << "\n";
	return 0;
}