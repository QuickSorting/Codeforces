#include <bits/stdc++.h>

using namespace std;

const int kN = 1e5 + 7;
const int kM = 2e5 + 7;
const int kInf = 1e9;

vector<int> adj[kN], adj_tr[kN];
bool used[kN], in_tree[kN];
int depth[kN];
int n, m, k;
vector<int> independent_set;

bool dfs_line(int start, int end){
	if(start == end){
		cout << end << " ";
		return true;
	}

	for(int to: adj_tr[start]){
		if(dfs_line(to, end)){
			cout << start << " ";
			return true;
		}
	}
	return false;
}

void answer_cycle(int start, int end){
	cout << "2\n";
	cout << depth[end] - depth[start] + 1 << "\n";
	dfs_line(start, end);
	exit(0);
}

int dfs(int u){
	used[u] = true;
	in_tree[u] = true;

	int curr_min = kInf, children;
	for(int to: adj[u]){
		if(used[to]){
			if(in_tree[to] && depth[u] - depth[to] + 1 >= k)
				answer_cycle(to, u);
			continue;	
		}

		++children;
		adj_tr[u].push_back(to);
		depth[to] = depth[u] + 1;
		curr_min = min(curr_min, dfs(to));
	}

	if(!children){
		independent_set.push_back(u);
		curr_min = 0;
	}
	else if(curr_min >= k - 1){
		independent_set.push_back(u);
		curr_min = 0;
	}

	in_tree[u] = false;
	return curr_min + 1;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for(int i = 0; i < m; ++i){
		int u, v;
		cin >> u >> v;

		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	k = sqrt(n);
	while(k * k < n)
		++k;

	dfs(1);

	cout << "1\n";
	for(int i = 0; i < k; ++i)
		cout << independent_set[i] << " ";
	cout << "\n";
}