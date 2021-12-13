#include <bits/stdc++.h>

using namespace std;

const long long kN = 2e5 + 7;

struct SegmentTree{
private:
	pair<long long, long long> nodes[4 * kN];

	inline pair<long long, long long> merge(pair<long long, long long> lvalue, pair<long long, long long> rvalue){
		return {lvalue.first + rvalue.first, lvalue.second + rvalue.second};
	}
public:
	SegmentTree(){
		for(long long i = 0; i < 4 * kN; ++i)
			nodes[i] = {0, 0};
	}

	void update(long long idx, long long l, long long r, long long s, pair<long long, long long> val){
		if(s < l || r < s)
			return;
		if(l == r){
			nodes[idx] = val;
			return;
		}

		long long mid = (l + r) >> 1;
		update(2 * idx, l, mid, s, val);
		update(2 * idx + 1, mid + 1, r, s, val);

		nodes[idx] = merge(nodes[2 * idx], nodes[2 * idx + 1]);
	}

	pair<long long, long long> query(int idx, int l, int r, int sl, int sr){
		if(sr < l || r < sl)
			return {0, 0};
		if(sl <= l && r <= sr)
			return nodes[idx];

		int mid = (l + r) >> 1;
		pair<long long, long long> lvalue = query(2 * idx, l, mid, sl, sr);
		pair<long long, long long> rvalue = query(2 * idx + 1, mid + 1, r, sl, sr);

		return merge(lvalue, rvalue);
	}
};

SegmentTree seg_tr;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long n;
	cin >> n;

	vector<pair<long long, long long>> p(n);
	for(int i = 0; i < n; ++i)
		cin >> p[i].first;
	for(int i = 0; i < n; ++i)
		cin >> p[i].second;

	sort(p.begin(), p.end());

	vector<pair<long long, long long>> compress;
	for(int i = 0; i < n; ++i)
		compress.push_back({p[i].second, i});

	sort(compress.begin(), compress.end());

	vector<int> idx(n);
	for(int i = 0; i < n; ++i)
		idx[compress[i].second] = i;

	for(int i = 0; i < n; ++i)
		seg_tr.update(1, 0, n - 1, idx[i], {p[i].first, 1});

	long long ans = 0, sum = 0;
	for(long long i = 0; i < n; ++i){
		ans += i * p[i].first - sum;
		sum += p[i].first;
	}

	for(int i = 0; i < n; ++i){
		seg_tr.update(1, 0, n - 1, idx[i], {0, 0});

		pair<long long, long long> q = seg_tr.query(1, 0, n - 1, 0, idx[i]);
		ans -= q.first;
		ans += q.second * p[i].first;
	}

	cout << ans << "\n";
}