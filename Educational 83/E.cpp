#include <bits/stdc++.h>

using namespace std;

const int kN = 507;

vector<int> a;

int find_curr2(int idx, int num, int direction){
	int n = a.size();

	if(a[idx] != num + 1)
		return 0;

	int cnt = 0;
	for(int i = idx; i >= 0 && i < n; i += direction){
		if(a[i] != num + 1)
			break;
		++cnt;
	}

	if(cnt % 2 == 0)
		return 0;
	if(cnt != 1)
		return 1;

	return find_curr2(idx + direction * cnt, num + 1, direction) + 1;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	a.resize(n);
	for(int i = 0; i < n; ++i)
		cin >> a[i];

	int ans = n;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n - i; ++j)
			cout << a[j] << " ";
		cout << "\n";

		int mn = 1007, mx2 = -1, idx = -1, new_n = n - i;
		for(int j = 0; j < new_n - 1; ++j){
			int curr2 = -1;
			if(j != 0)
				curr2 = max(find_curr2(j - 1, a[j], -1), curr2);
			if(j != new_n - 2)
				curr2 = max(find_curr2(j + 2, a[j], 1), curr2);

			if(a[j] == a[j + 1] && (a[j] < mn || (a[j] == mn && curr2 > mx2))){
				mn = a[j];
				idx = j;
				mx2 = curr2;
			}
		}

		if(idx == -1){
			cout << new_n << "\n";
			return 0;
		}

		a.erase(a.begin() + idx);
		a.erase(a.begin() + idx);	
		a.insert(a.begin() + idx, mn + 1);
		ans = new_n;
	}

	cout << ans << "\n";
}
/*
11
4 3 3 3 2 2 2 2 2 3 4
*/ 