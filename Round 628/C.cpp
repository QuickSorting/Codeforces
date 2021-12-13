#include <bits/stdc++.h>

using namespace std;

const int kN = 1e5 + 7;

pair<int, int> e[kN];
vector<int> adj[kN];
int val[kN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for(int i = 0; i < n - 1; ++i){
		cin >> e[i].first >> e[i].second;

		adj[e[i].first].push_back(i);
		adj[e[i].second].push_back(i);
	}

	int big = -1;
	for(int i = 1; i <= n; ++i){
		if(adj[i].size() >= 3){
			big = i;
			break;
		}
	}

	if(big == -1){
		for(int i = 0; i < n - 1; ++i)
			cout << i << "\n";
		return 0;
	}

	for(int i = 0; i < n - 1; ++i)
		val[i] = -1;

	val[adj[big][0]] = 0;
	val[adj[big][1]] = 1;
	val[adj[big][2]] = 2;

	int curr = 3;
	for(int i = 0; i < n - 1; ++i)
		if(val[i] == -1)
			val[i] = curr++;

	for(int i = 0; i < n - 1; ++i)
		cout << val[i] << "\n";
}