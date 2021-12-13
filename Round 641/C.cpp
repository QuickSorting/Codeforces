#include <bits/stdc++.h>

using namespace std;

const int k_N = 1000 + 3;
long long k_Inf = 1e18;

string s[k_N];
bool b[k_N][k_N];
long long it[k_N][k_N];
bool visited[k_N][k_N];

int n, m, t;

int main(){
    k_Inf += 7;
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> t;

    for(int i = 0; i < n; ++i)
        cin >> s[i];

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            array<pair<int, int>, 4> adj{pair<int, int>{i + 1, j}, {i - 1, j}, {i, j + 1}, {i, j - 1}};
            for(auto [x, y]: adj){
                if(x < 0 || x > n - 1 || y < 0 || y > m - 1)
                    continue;
                if(s[x][y] == s[i][j]){
                    b[i][j] = true;
                    break;
                }
            }
        }
    }

    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            it[i][j] = k_Inf;

    queue<pair<int, int>> bfs;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(b[i][j]){
                it[i][j] = 1;
                bfs.push({i, j});
                visited[i][j] = true;
            }
        }
    }

    while(!bfs.empty()){
        auto [x, y] = bfs.front();
        bfs.pop();

        array<pair<int, int>, 4> adj{pair<int, int>{x + 1, y}, {x - 1, y}, {x, y + 1}, {x, y - 1}};
        for(auto [x_to, y_to]: adj){
            if(x_to < 0 || x_to > n - 1 || y_to < 0 || y_to > m - 1)
                continue;
            if(!visited[x_to][y_to]){
                visited[x_to][y_to] = true;
                it[x_to][y_to] = it[x][y] + 1;
                bfs.push({x_to, y_to});
            }
        }
    }

    for(int i = 0; i < t; ++i){
        int x, y;
        long long p;
        cin >> x >> y >> p;
        --x;
        --y;

        if(p < it[x][y]){
            cout << s[x][y] << "\n";
            continue;
        }

        if((p - it[x][y]) & 1)
            cout << s[x][y] << "\n";
        else{
            if(s[x][y] == '0')
                cout << '1' << "\n";
            else
                cout << '0' << "\n";
        }
    }
}
/*
1 1 3
1
1 1 1
1 1 2
1 1 1000000000000000000
*/