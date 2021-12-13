#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 7;

int a[MAXN], ans[MAXN];



struct cmp{
	bool operator()(int lvalue, int rvalue)const{
		return calc(lvalue) < calc(rvalue);
	}
};

set<int, cmp> st;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;

	cin >> n;

	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}
	int mn, mx;
	mn = mx = a[0];

	for(int i = 0; i < n; ++i){
		mn = min(mn, a[i]);
		mx = max(mx, a[i]);
	}

	if(2 * mn >= mx){
		for(int i = 0; i < n; ++i){
			cout << "-1 ";
		}
		cout << "\n";

		return 0;
	}

	for(int i = 0; i < n; ++i){
		auto it = st.lower_bound(i);
		vector<int> to_erase;
		while(it != st.end()){
			to_erase.push_back(*it);
			ans[*it] = i - *it;
			++it;
		}
		for(auto p: to_erase){
			st.erase(p);
		}
		st.insert({a[i], i});
	}
	for(int i = 0; i < n; ++i){
		auto it = st.lower_bound(i);
		vector<int> to_erase;
		while(it != st.end()){
			to_erase.push_back(*it);
			ans[*it] = i - *it + n;
			++it;
		}
		for(auto p: to_erase){
			st.erase(p);
		}
	}

	for(int i = 0; i < n; ++i){
		cout << ans[i] << " ";
	}
	cout << "\n";

	return 0;
}