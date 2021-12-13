#include <bits/stdc++.h>

using namespace std;

const long long MAXN = 4e5 + 7;

mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int mod){
	return mt() % mod;
}

struct fenwick{
	pair<long long, long long> tr[MAXN];

	fenwick(){}
	void clear(){
		for(long long i = 0; i < MAXN; ++i)
			tr[i] = {0, 0};
	}

	void update(long long idx, long long val){
		for(; idx < MAXN; idx += (idx & -idx)){
			tr[idx].first += val;
			tr[idx].second ^= val;
		}
	}

	pair<long long, long long> query(long long idx){
		pair<long long, long long> ret = {0, 0};
		for(; idx >= 1; idx -= (idx & -idx)){
			ret.first += tr[idx].first;
			ret.second ^= tr[idx].second;
		}
		return ret;
	}

	pair<long long, long long> query(long long l, long long r){
		pair<long long, long long> lvalue = query(l - 1);
		pair<long long, long long> rvalue = query(r);

		return make_pair(rvalue.first - lvalue.first, rvalue.second ^ lvalue.second);
	}
};

struct fenwick2{
	pair<long long, long long> tr[MAXN];

	fenwick2(){}
	void clear(){
		for(long long i = 0; i < MAXN; ++i)
			tr[i] = {0, 0};
	}

	void update(long long idx, long long val){
		for(; idx < MAXN; idx += (idx & -idx)){
			if(val > 0){
				tr[idx].first += val;
				tr[idx].second ^= val;
			}
			else{
				tr[idx].first += val;
				tr[idx].second ^= (-val);
			}
		}
	}

	pair<long long, long long> query(long long idx){
		pair<long long, long long> ret = {0, 0};
		for(; idx >= 1; idx -= (idx & -idx)){
			ret.first += tr[idx].first;
			ret.second ^= tr[idx].second;
		}
		return ret;
	}

	void update(long long l, long long r, long long val){
		update(l, val);
		update(r + 1, -val);
	}
};

fenwick f1, f2;
fenwick2 f3, f4;

set<long long> exist;
map<long long, long long> idx;
array<long long, 4> arr[MAXN];
long long perm[MAXN];

pair<long long, long long> ans1[MAXN], ans2[MAXN];
pair<long long, long long> point1[MAXN], point2[MAXN];

pair<long long, long long> merge(pair<long long, long long> lvalue, pair<long long, long long> rvalue){
	pair<long long, long long> ret;
	ret.first = lvalue.first + rvalue.first;
	ret.second = lvalue.second ^ rvalue.second;
	return ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long n;
	cin >> n;

	for(long long i = 0; i < n; ++i){
		for(long long j = 0; j < 4; ++j){
			cin >> arr[i][j];
			exist.insert(arr[i][j]);
		}
	}

	long long cnt = 1;
	for(long long x: exist)
		idx[x] = cnt++;

	for(long long i = 0; i < n; ++i)
		perm[i] = i + 1;
	random_shuffle(perm, perm + n, rnd);
	long long q = 1;
	while(q--){
		for(int i = 0; i < n; ++i){
			point1[idx[arr[i][0]]] = merge(point1[idx[arr[i][0]]], {perm[i], perm[i]});
			point1[idx[arr[i][1]]] = merge(point1[idx[arr[i][1]]], {perm[i], perm[i]});
			point2[idx[arr[i][2]]] = merge(point2[idx[arr[i][2]]], {perm[i], perm[i]});
			point2[idx[arr[i][3]]] = merge(point2[idx[arr[i][3]]], {perm[i], perm[i]});
		}

		for(long long i = 0; i < n; ++i){
			f1.update(idx[arr[i][0]], perm[i]);
			f1.update(idx[arr[i][1]], perm[i]);

			f2.update(idx[arr[i][2]], perm[i]);
			f2.update(idx[arr[i][3]], perm[i]);

			f3.update(idx[arr[i][0]], idx[arr[i][1]], perm[i]);
			f4.update(idx[arr[i][2]], idx[arr[i][3]], perm[i]);
		}

		/*for(long long i = 1; i < cnt; ++i){
			cout << i << endl;
			cout << f1.query(i, i).first << " " << f1.query(i, i).second << " f1" << endl;
			cout << f2.query(i, i).first << " " << f2.query(i, i).second << " f2" << endl;
			cout << f3.query(i).first << " " << f3.query(i).second << " f3" << endl;
			cout << f4.query(i).first << " " << f4.query(i).second << " f4" << endl;
		}*/

		for(long long i = 0; i < n; ++i){
			ans1[perm[i]] = merge(ans1[perm[i]], f1.query(idx[arr[i][0]], idx[arr[i][1]]));
			ans2[perm[i]] = merge(ans2[perm[i]], f2.query(idx[arr[i][2]], idx[arr[i][3]]));

			ans1[perm[i]] = merge(ans1[perm[i]], f3.query(idx[arr[i][0]]));
			ans1[perm[i]] = merge(ans1[perm[i]], f3.query(idx[arr[i][1]]));

			ans2[perm[i]] = merge(ans2[perm[i]], f4.query(idx[arr[i][2]]));
			ans2[perm[i]] = merge(ans2[perm[i]], f4.query(idx[arr[i][3]]));

			ans1[perm[i]].first -= point1[idx[arr[i][0]]].first;
			ans1[perm[i]].second ^= point1[idx[arr[i][0]]].second;

			ans1[perm[i]].first -= point1[idx[arr[i][1]]].first;
			ans1[perm[i]].second ^= point1[idx[arr[i][1]]].second;

			ans2[perm[i]].first -= point2[idx[arr[i][2]]].first;
			ans2[perm[i]].second ^= point2[idx[arr[i][2]]].second;

			ans2[perm[i]].first -= point2[idx[arr[i][3]]].first;
			ans2[perm[i]].second ^= point2[idx[arr[i][3]]].second;

			ans1[perm[i]] = merge(ans1[perm[i]], {perm[i], perm[i]});
			ans1[perm[i]] = merge(ans1[perm[i]], {perm[i], perm[i]});
			ans2[perm[i]] = merge(ans2[perm[i]], {perm[i], perm[i]});
			ans2[perm[i]] = merge(ans2[perm[i]], {perm[i], perm[i]});
		}

		for(int i = 1; i <= n; ++i){
			if(ans1[i] != ans2[i]){
				cout << "NO\n";
				return 0;
			}
		}
		

		if(q){
			f1.clear();
			f2.clear();
			f3.clear();
			f4.clear();
			for(long long i = 1; i <= n; ++i){
				ans1[i] = {0, 0};
				ans2[i] = {0, 0};
			}
			for(long long i = 0; i < MAXN; ++i){
				point1[i] = {0, 0};
				point2[i] = {0, 0};
			}
		}
	}

	cout << "YES\n";
	return 0;
}