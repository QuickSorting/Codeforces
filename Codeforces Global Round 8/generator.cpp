#include <bits/stdc++.h>

using namespace std;

mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());

vector<pair<int, int>> edges;

int rnd(int mod){
    return mt() % mod;
}

int main(){
    int n = mt() % 10 + 1;
    for(int i = 1; i < n; ++i){
        int x = mt() % 3;

        for(int j = 0; j < x; ++j){
            int curr = i + 1 + mt() % (n - i);
            edges.push_back({i, curr});
        }
    }

    cout << 1 << "\n";
    cout << n << " ";

    random_shuffle(edges.begin(), edges.end(), rnd);

    cout << edges.size() << "\n";
    for(auto p: edges)
        cout << p.first << " " << p.second << "\n";
}