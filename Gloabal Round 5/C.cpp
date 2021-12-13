#include <bits/stdc++.h>

using namespace std;

const long long MAXN = 5e4 + 7;
const long long MAXC = 1e8 + 7;
const long long inf = 1e18 + 3;

array<long long, 4> p[MAXN];
bool used[MAXN];

long long dist(long long x, long long y){
	long long ret = 0;
	for(int i = 0; i < 3; ++i){
		ret += abs(p[x][i] - p[y][i]);
	}
	return ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long n;
	cin >> n; 

	for(long long i = 0; i < n; ++i){
		cin >> p[i][0] >> p[i][1] >> p[i][2];
		p[i][3] = i + 1;
	}
	sort(p, p + n);
	int start = 0, pr = -1;
	for(long long i = 1; i < n; ++i){
		if(p[i][0] != p[i - 1][0]){
			if((i - start) & 1){
				for(int j = start; j <= i - 2; j += 2){
					cout << p[j][3] << " " << p[j + 1][3] << "\n";
				}
				if(pr == -1){
					pr = i - 1;
				}
				else{
					cout << p[pr][3] << " " << p[i - 1][3] << "\n";
					pr = -1;
				}
			}
			else{
				for(int j = start; j <= i - 1; j += 2){
					cout << p[j][3] << " " << p[j + 1][3] << "\n";
				}
			}
			start = i;
		}
	}

	long long i = n;
	if((i - start) & 1){
		for(int j = start; j <= i - 2; j += 2){
			cout << p[j][3] << " " << p[j + 1][3] << "\n";
		}
		if(pr == -1){
			pr = i - 1;
		}
		else{
			cout << p[pr][3] << " " << p[i - 1][3] << "\n";
			pr = -1;
		}
	}
	else{
		for(int j = start; j <= i - 1; j += 2){
			cout << p[j][3] << " " << p[j + 1][3] << "\n";
		}
	}

	return 0;
}