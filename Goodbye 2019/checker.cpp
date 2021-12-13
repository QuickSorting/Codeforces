#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1007;

pair<long long, long long> p[MAXN];

long long square(long long x){
	return x * x;
}

long long dist(int i, int j){
	return square(p[i].first - p[j].first) + square(p[i].second - p[j].second);
}

int type[MAXN];
map<long long, bool> type_dist;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	ifstream in1("input.txt");

	int n;
	in1 >> n;

	for(int i = 1; i <= n; ++i)
		in1 >> p[i].first >> p[i].second;

	for(int i = 1; i <= n; ++i){
		type[i] = 2;
	}

	for(int i = 1; i <= n; ++i)
		for(int j = i + 1; j <= n; ++j)
			if(p[i] == p[j]){
				cout << "OK\n";
				return 0;
			}

	ifstream in2("output.txt");

	int k;
	in2 >> k;
	for(int i = 0; i < k; ++i){
		int idx;
		in2 >> idx;

		type[idx] = 1;
	}

	for(int i = 1; i <= n; ++i){
		for(int j = i + 1; j <= n; ++j){
			if(type_dist.count(dist(i, j))){
				if(type_dist[dist(i, j)] != (type[i] == type[j])){
					cout << "WRONGGGG " << i << " " << j << " with distance " << dist(i, j) << endl;
					return 0;
				}
			}
			type_dist[dist(i, j)] = (type[i] == type[j]);
		}
	}

	cout << "OK" << endl;
}