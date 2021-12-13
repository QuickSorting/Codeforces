#include <bits/stdc++.h>

using namespace std;

const long long MAXM = 4e5 + 7;
const long long LOGM = 20;

vector<long long> adj[MAXM];
long long up[MAXM][LOGM], lvl[MAXM];
long long n, m, w[MAXM];
bool used[MAXM];

void dfs(long long u, long long par){
	//cout << u << " -> " << par << endl; 
	up[u][0] = par;
	lvl[u] = lvl[par] + 1;
	used[u] = true;

	for(long long to: adj[u]){
		if(to == par || used[to]){
			continue;
		}
		dfs(to, u);
	}
}

long long s;

long long lca(long long x, long long y){
	if(lvl[x] < lvl[y]){
		swap(x, y);
	}

	long long diff = (lvl[x] - lvl[y]);

	if(diff){
		for(long long j = 0; j < LOGM; ++j){
			if((1 << j) & diff){
				x = up[x][j];
			}
		}
	}

	//cout << x << " level " << y << endl; 

	if(x == y){
		return x;
	}

	for(long long j = 0; j < LOGM; ++j){
		if(up[x][j] != up[y][j]){
			x = up[x][j];
			y = up[y][j];
		}
	}

	return up[x][0];
}

void init_lca(){
	dfs(s, s);
	for(long long j = 1; j < LOGM; ++j){
		for(long long i = 1; i <= n; ++i){
			up[i][j] = up[up[i][j - 1]][j - 1];
		}
	}
}

long long ans2 = 0;

long long dfs2(long long u, long long par = -1){
	long long mn_lvl = lvl[u] + 1;

	used[u] = true;

	for(long long to: adj[u]){
		if(to == par){
			continue;
		}

		long long curr;
		if(used[to]){
			curr = lvl[lca(u, to)];
			//cout << curr << " lca " << u << " " << to << endl;
		}
		else{
			curr = dfs2(to, u);
		}
		mn_lvl = min(mn_lvl, curr);
	}
	if(mn_lvl != lvl[u] + 1){
		mn_lvl = 1;
	}

	if(lvl[u] >= mn_lvl){
		//cout << u << " " << par << " u par, w - " << w[u] << " " << w[par] << endl;
		//w[par] += w[u];
		ans2 += w[u];
		w[u] = 0;
	}

	return mn_lvl;
}

long long solve(long long u, long long par = -1){
	used[u] = true;

	long long ans = 0;
	for(long long to: adj[u]){
		if(to == par || used[to]){
			continue;
		}

		ans = max(ans, solve(to, u));
	}

	ans += w[u];

	return ans;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for(long long i = 1; i <= n; ++i){
		cin >> w[i];
	}

	for(long long i = 0; i < m; ++i){
		long long u, v;

		cin >> u >> v;

		adj[u].push_back(v);
		adj[v].push_back(u);
	}


	cin >> s;
	init_lca();

	for(long long i = 1; i <= n; ++i){
		used[i] = false;
	}
	dfs2(s, -1);
	for(long long i = 1; i <= n; ++i){
		used[i] = false;
	}
	cout << solve(s) + ans2 << "\n";

	return 0;
}