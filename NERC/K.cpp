#include <bits/stdc++.h>

using namespace std;

set<vector<int>> s;
int n;

vector<int> do_1(vector<int> p){
    for(int i = 0; i < 2 * n; i += 2)
        swap(p[i], p[i + 1]);
    return p;
}

vector<int> do_2(vector<int> p){
    for(int i = 0; i < n; ++i)
        swap(p[i], p[i + n]);
    return p;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    vector<int> p(2 * n);
    for(int i = 0; i < 2 * n; ++i)
        cin >> p[i];
    queue<pair<int, vector<int>>> q;
    q.push({0, p});
    s.insert(p);

    while(!q.empty()){
        auto [dist, u] = q.front();
        q.pop();

        if(dist > 6) break;

        bool ok = true;
        for(int i = 0; i < 2 * n; ++i)
            if(u[i] != i + 1){
                ok = false;
                break;
            }
        if(ok){
            cout << dist << "\n";
            return 0;
        }

        vector<int> to_1 = do_1(u);
        if(!s.count(to_1)){
            q.push({dist + 1, to_1});
            s.insert({to_1});
        }
        vector<int> to_2 = do_2(u);
        if(!s.count(to_2)){
            q.push({dist + 1, to_2});
            s.insert({to_2});
        }
    }
    cout << "-1\n";
}