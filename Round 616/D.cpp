#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, k;
	cin >> n >> k;

	for(int i = 1; i <= n; i += k){
		

		for(int j = 1; j <= n; ++j){
			if(j >= i && j < i + k)
				continue;
			for(int j2 = 1; j2 <= min(n, i + k - 1); ++j2){
				cout << "? " << j2 << "\n";
				fflush(stdout);
				char c;
				cin >> c;
			}

			cout << "? " << j << "\n";
			fflush(stdout);
			char c;
			cin >> c;
		}
	}
}