#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 7;

int a[MAXN], b[MAXN];

clock_t timer = clock();
int ans = n + 1, sh = 0;
bool used[MAXN];

bool time_left(){
	return (((float)clock() - (float)timer) / (float)CLOCKS_PER_SEC) <= (float)1.9;
}

int dfs(int u){
	if(used[u]){
		return b[u];
	}

	used[u] = true;
	b[u] = 1 + dfs(b[u]);

	return b[u];
}

int calc(int x){
	int curr = 0;

	stack<int> st;
	for(int i = x; i < n; ++i){
		while(!st.empty() && a[i] > a[st.top()]){
			b[st.top()] = i;
			st.pop();
		}
		st.push(i);
	}
	for(int i = 0; i < x; ++i){
		while(!st.empty() && a[i] > a[st.top()]){
			b[st.top()] = i;
			st.pop();
		}
		st.push(i);
	}

	while(!st.empty()){
		b[st.top()] = -1;
	}

	for(int i = 0; i < n; ++i){
		dfs(i);
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;

	cin >> n;

	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}
}