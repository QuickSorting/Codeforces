#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }
#define all(x) (x).begin(), (x).end()

const int N = 64 + 3;
const int M = 256 + 3;

int n, m;
vector<int> adj[N];
vector<int> cycles;
vector<array<int, 3>> c_adj[N][N];
vector<int> cnt;
vector<int> idx_cnt[3];

bool edge_exists(int a, int b){
    return find(all(adj[a]), b) != adj[a].end();
}

void solve(){
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
        adj[i].clear();
    for(int i = 1; i <= n; ++i)
        for(int j = i - 1; j >= 1; --j)
            c_adj[i][j].clear();
    cycles.clear();
    cnt.clear();
    for(int i = 0; i <= 3; ++i)
        idx_cnt[i].clear();

    for(int i = 0; i < m; ++i){
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for(int i = 1; i <= n; ++i)
        sort(all(adj[i]));

    for(int i = 1; i <= n; ++i){
        for(int to: adj[i]){
            if(to > i) break;
            int from, other;
            if(adj[to].size() < adj[i].size()){
                from = to;
                other = i;
            }
            else{
                from = i;
                other = to;
            }

            for(int to2: adj[from]){
                if(to2 > to) break;
                if(find(all(adj[other]), to2) != adj[other.size()]){
                    int idx = cycles.size();
                    c_adj[i][to].push_back(idx);
                    c_adj[i][to2].push_back(idx);
                    c_adj[to][to2].push_back(idx);
                    cycles.push_back({i, to, to2});
                    cnt.push_back(edge_exists(i, to) + edge_exists(i, to2) + edge_exists(to, to2));
                    idx_cnt[cnt.back()].push_back(idx);
                }
            }
        }
    }

    int c_left = cycles.size();
    for(int i = 0)
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--)
        solve();
}