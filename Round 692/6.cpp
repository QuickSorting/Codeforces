#include <bits/stdc++.h>

using namespace std;

const int K = 26;
const int INF = 1e9 + 7;

struct Vertex {
    int next[K];
    int leaf = false;
    int p = -1;
    char pch;
    int link = -1;
    int go[K];

    Vertex(int p=-1, char ch='$') : p(p), pch(ch) {
        fill(begin(next), end(next), -1);
        fill(begin(go), end(go), -1);
    }
};

vector<Vertex> t(1);

void add_string(string const& s) {
    int v = 0;
    for (char ch : s) {
        int c = ch - 'a';
        if (t[v].next[c] == -1) {
            t[v].next[c] = t.size();
            t.emplace_back(v, ch);
        }
        v = t[v].next[c];
    }
    ++t[v].leaf;
}

int go(int v, char ch);

int get_link(int v) {
    if (t[v].link == -1) {
        if (v == 0 || t[v].p == 0)
            t[v].link = 0;
        else
            t[v].link = go(get_link(t[v].p), t[v].pch);
    }
    return t[v].link;
}

int go(int v, char ch) {
    int c = ch - 'a';
    if (t[v].go[c] == -1) {
        if (t[v].next[c] != -1)
            t[v].go[c] = t[v].next[c];
        else
            t[v].go[c] = v == 0 ? 0 : go(get_link(v), ch);
    }
    return t[v].go[c];
}

int n, k;
string p[1003];
const int MX = 1000 + 3;
const int N = 100 + 3;

queue<pair<int, int>> q;
pair<int, int> par[MX][N];
bool vis[MX][N];
char letter[MX][N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    for(int i = 0; i < k; ++i){
        cin >> p[i];
        add_string(p[i]);
    }

    for(int i = 0; i < t.size(); ++i)
        t[i].leaf += t[get_link(i)].leaf;

    q.push({0, 0});
    vis[0][0] = true;

    pair<int, int> endpoint;
    while(!q.empty()){
        auto [i, j] = q.front();
        q.pop();

        int curr = j;
        curr += t[i].leaf;
        if(curr >= n){
            endpoint = {i, j};
            break;
        }

        for(char c = 'a'; c <= 'z'; ++c){
            int to = go(i, c);
            if(!vis[to][curr]){
                vis[to][curr] = true;
                par[to][curr] = {i, j};
                letter[to][curr] = c;
                q.push({to, curr});
            }
        }
    }

    auto [i, j] = endpoint;
    string ans = "";
    while(i != 0 || j != 0){
        ans += letter[i][j];
        pair<int, int> p = par[i][j];
        i = p.first;
        j = p.second;
    }
    reverse(ans.begin(), ans.end());

    cout << ans << "\n";
}
/*
3 2
b
ab
*/