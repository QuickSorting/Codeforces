#include <bits/stdc++.h>

using namespace std;

const int kN = 101;

pair<int, int> query(int x){
	cout << "+ " << x << "\n";
	fflush(stdout);

	pair<int, int> answer;
	cin >> answer.first >> answer.second;

	return answer;
}

int a[kN], lookup[4 * kN * kN];
int diff_straight[kN];
int n, straight, triplet;

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(NULL);

	for(int i = 0; i <= 2 * n; ++i)
		lookup[(i * (i - 1)) / 2] = i;

	cin >> n;
	cin >> triplet >> straight;

	if(n & 1){
		int new_triplet, new_straight, diff;
		for(int i = 1; i <= n; i += 2){
			auto p = query(i);
			new_triplet = p.first;
			new_straight = p.second;

			diff = new_triplet - triplet;

			triplet = new_triplet;
			straight = new_straight;
		}

		for(int i = 1; i <= n; i += 2){
			auto p = query(i);
			new_triplet = p.first;
			new_straight = p.second;

			diff = new_triplet - triplet;
			diff_straight[i] = new_straight - straight;

			triplet = new_triplet;
			straight = new_straight;
			if(diff != 0)
				a[i] = lookup[diff] - 1;
			else
				a[i] = 0;
		}

		for(int i = 2; i <= n; i += 2){
			int sum = diff_straight[i - 1];
			if(i >= 3)
				sum -= (a[i - 2] + 1) * (a[i - 3] + 2);

			int div = 0;
			if(i >= 2)
				div += a[i - 2];
			div += a[i + 1];

			a[i] = sum / div;
		}
	}
	else{
		int new_triplet, new_straight, diff;
		for(int i = 1; i <= n; ++i){
			if(i % 2 == 0 && i != n - 2)
				continue;
			if(i == n - 1)
				continue;
			auto p = query(i);
			new_triplet = p.first;
			new_straight = p.second;

			diff = new_triplet - triplet;

			triplet = new_triplet;
			straight = new_straight;
		}

		for(int i = 1; i <= n; ++i){
			if(i % 2 == 0 && i != n - 2)
				continue;
			if(i == n - 1)
				continue;
			auto p = query(i);
			new_triplet = p.first;
			new_straight = p.second;

			diff = new_triplet - triplet;
			diff_straight[i] = new_straight - straight;

			triplet = new_triplet;
			straight = new_straight;
			if(diff != 0)
				a[i] = lookup[diff] - 1;
			else
				a[i] = 0;
		}

		for(int i = 1; i <= n; ++i){
			if(i % 2 != 0 && i != n - 1)
				continue;
			int sum = diff_straight[i - 1];
			if(i >= 3)
				sum -= (a[i - 2] + 1) * (a[i - 3] + 2);

			int div = 0;
			if(i >= 2)
				div += a[i - 2];
			div += a[i + 1];

			a[i] = sum / div;
		}
	}


	cout << "! ";
	for(int i = 1; i <= n; ++i)
		cout << a[i] << " ";
	cout << "\n";
	fflush(stdout);
}