#include <bits/stdc++.h>
 
using namespace std;
 
const int MAXN = 1e3 + 7;
 
pair<long long, long long> p[MAXN];
short group[MAXN];
map<long long, int> cnt;
bool used[MAXN];
int n;
 
long long dist(int i, int j){
	return (p[i].first - p[j].first) * (p[i].first - p[j].first) + (p[i].second - p[j].second) * (p[i].second - p[j].second);
}
 
void dfs(int u){
	used[u] = true;
 
	vector<pair<long long, int> > d;
	for(int i = 0; i < n; ++i){
		if(u == i || used[i])
			continue;
		long long curr_d = dist(u, i);
		if(cnt[curr_d] != 1)
			d.push_back({dist(u, i), i});
	}
	sort(d.begin(), d.end());
 
	for(pair<long long, int> x: d){
		int i = x.second;
 
		if(u == i || used[i])
			continue;
		if(cnt[x.first] == 1)
			continue;
 
		group[i] = ((group[u] == 1) ? 2 : 1);
		dfs(i);
	}
}
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
 
	cin >> n;
 
	for(int i = 0; i < n; ++i)
		cin >> p[i].first >> p[i].second;
 
	for(int i = 0; i < n; ++i)
		group[i] = -1;
	group[0] = 1;
 
	for(int i = 0; i < n; ++i){
		for(int j = i + 1; j < n; ++j){
			cnt[dist(i, j)] += 1;
		}
	}
 
	dfs(0);
	for(int i = 1; i < n; ++i){
		if(!used[i]){
			group[i] = 1;
			dfs(i);
		}
	}
 
	vector<int> ans;
	for(int i = 0; i < n; ++i){
		if(group[i] == 1)
			ans.push_back(i + 1);
	}
 
	cout << (int)ans.size() << "\n";
	for(int x: ans)
		cout << x << " ";
	cout << "\n";
}