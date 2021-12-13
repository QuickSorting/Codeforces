#include <bits/stdc++.h>

using namespace std;

#define endl "\n";
mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());

int h;

int query(int u, int v, int w){
    cout <<"? " <<  u << " " << v << " " << w << endl;
    cout.flush();
    int ans;
    cin >> ans;
    return ans;
}

void answer(int ans){
    cout << "! " << ans << endl;
    cout.flush();
    exit(0);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> h;
    int n = (1 << h) - 1;

    map<int, int> cnt;
    for(int i = 0; i < 410; ++i){
        int u = mt() % n + 1, v = mt() % n + 1, w = mt() % n + 1;
        if(u == v || v == w || u == w){
            i--;
            continue;
        }
        cnt[query(u, v, w)]++;
    }

    vector<array<int, 2>> v;
    for(auto [x, y]: cnt)
        v.push_back({y, x});

    sort(v.begin(), v.end(), greater<array<int, 2>>());

    /*if(v.size() >= 3){
        if(query(v[0][1], v[1][1], v[2][1]) == v[2][1]) answer(v[2][1]);
        if(query(v[0][1], v[2][1], v[1][1]) == v[1][1]) answer(v[1][1]);
        if(query(v[1][1], v[2][1], v[0][1]) == v[0][1]) answer(v[0][1]);
    }*/

    for(int i = 1; i <= n; ++i){
        if(i == v[0][1] || i == v[1][1]) continue;
        if(query(v[0][1], v[1][1], i) == i) answer(i);
    }

    answer(-1);
}