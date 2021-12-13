#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        int n, m;
        cin >> n >> m;

        static int a[103][103];

        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                cin >> a[i][j];
                if((a[i][j] + i + j) & 1)
                    a[i][j]++;
            }
        }

        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j)
                cout << a[i][j] << " ";
            cout << '\n';
        }
    }
}