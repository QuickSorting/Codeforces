#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 3;
const int MAX = 2.5e6 + 3;

int n, a[N];
clock_t timer = clock();
mt19937 mt(23);

vector<pair<int, int>> mp[2 * MAX]; 

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> a[i];

    sort(a, a + n);

    while(((float)clock() - timer) / (float)CLOCKS_PER_SEC <= 1.5){
        int x = mt() % n;
        int y = mt() % n;
        if(x == y) continue; 
    
        int sum = a[x] + a[y];
        for(auto [x2, y2]: mp[sum]){
            if(x2 != x && x2 != y && y2 != x && y2 != y){
                cout << "YES\n";
                cout << x + 1 << " " << y + 1 << " " << x2 + 1 << " " << y2 + 1 << "\n";
                return 0;
            }
        }
        mp[sum].push_back({x, y});
    }

    cout << "NO\n";
}
