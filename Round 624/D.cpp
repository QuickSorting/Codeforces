#include <bits/stdc++.h>

using namespace std;

const int kMaxN = 20007;
const int inf = 1e9;

vector<int> divisors[kMaxN];
mt19937 mt(7);

int a, b, c;
int mx = 0;

int m_rand(int l, int r){
	return mt() % (r - l + 1) + l;
}

void solve(){
	int ans = inf;
	int ans_a, ans_b, ans_c;
	for(int i = 1; i < kMaxN; ++i){
		int curr = abs(b - i);
		int curr_a, curr_b = i, curr_c;

		auto it = lower_bound(divisors[i].begin(), divisors[i].end(), a);
		int c1 = inf, c2 = inf;

		if(it != divisors[i].end())
			c1 = abs(a - *it);
		if(it != divisors[i].begin()){
			--it;
			c2 = abs(a - *it);
			++it;
		}

		curr += min(c1, c2);
		if(c1 < c2)
			curr_a = *it;
		else{
			--it;
			curr_a = *it;
		}

		int x = c / i;
		int c3 = c - (x * i), c4 = ((x + 1) * i) - c;

		curr += min(c3, c4);
		if(c3 < c4)
			curr_c = x * i;
		else
			curr_c = (x + 1) * i;

		if(curr < ans){
			ans = curr;
			ans_a = curr_a;
			ans_b = curr_b;
			ans_c = curr_c;
		}
	}

	if(ans_b > mx){
		mx = ans_b;
		cout << mx << " new max" << endl;
		cout << a << " " << b << " " << c << endl;
		cout << endl;
	}

	if(ans_b >= kMaxN){
		cout << a << " " << b << " " << c << "\n";
		cout << ans_b << "\n";
		exit(0);
	}
}

void preprocess(){
	for(int i = 1; i < kMaxN; ++i){
		for(int j = 1; j * j <= i; ++j){
			if(i % j == 0){
				divisors[i].push_back(j);
				if(j * j != i)
					divisors[i].push_back(i / j);
			}
		}
		sort(divisors[i].begin(), divisors[i].end());
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	preprocess();

	for(b = 10000; b >= 1; --b)
		for(c = 10000; c >= 1; --c)
			for(a = 1; a <= 10000; ++a)
				solve();
}