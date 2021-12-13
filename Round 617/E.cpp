#include <bits/stdc++.h>

using namespace std;

const int kMaxN = 207;

bool conn[kMaxN][kMaxN];
bool curr[kMaxN], used[kMaxN];
int n;
string s;

void dfs(int u){
	used[u] = true;

	for(int i = 0; i < n; ++i){
		if(!conn[u][i] && !conn[i][u])
			continue;
		if(used[i]){
			if(curr[i] == curr[u]){
				cout << "NO\n";
				exit(0);
			}
			continue;
		}

		curr[i] = !curr[u];
		dfs(i);
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> s;

	for(int i = 0; i < n; ++i){
		for(int j = i + 1; j < n; ++j){
			if(s[i] > s[j])
				conn[i][j] = true;
		}
	}

	for(int i = 0; i < n; ++i){
		if(!used[i]){
			dfs(i);
		}
	}

	cout << "YES\n";
	for(int i = 0; i < n; ++i)
		cout << curr[i];
	cout << "\n";
}