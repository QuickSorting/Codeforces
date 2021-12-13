#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3e5 + 7;

long long count(const vector<int> &p){
	long long cnt = 0;
	for(int i = 0; i < (int)p.size(); ++i){
		int mn = p[i], mx = p[i];
		for(int j = i; j < (int)p.size(); ++j){
			mn = min(p[j], mn);
			mx = max(p[j], mx);

			if(mx - mn == j - i)
				++cnt;
		}
	}

	return cnt;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long n, m;
	cin >> n;
	vector<int> p;
	for(int i = 0; i < n; ++i)
		p.push_back(i + 1);
	long long ans = 0;
	do{
		ans += count(p);
	}
	while(next_permutation(p.begin(), p.end()));

	cout << ans << endl;

	return 0;
}