#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 3;

int n;
map<vector<int>, vector<int>> p;

void output(const vector<int> &v){
    for(int x: v) cout << x << " ";
    cout << endl;
}

void bfs(vector<int> start){
    queue<vector<int>> q;
    p[start] = {};
    q.push(start);

    while(!q.empty()){
        auto v = q.front();
        q.pop();

        for(int i = 0; i < n; ++i)
            for(int j = i + 1; j < n; ++j){
                vector<int> to = v;
                swap(to[i], to[j]);
                to[i] = -to[i];
                to[j] = -to[j];
                if(!p.count(to)){
                    p[to] = v;
                    q.push(to);
                }
                to[i] = -to[i];
                to[j] = -to[j];
                swap(to[i], to[j]);
            }
    }

    vector<int> end(n);
    for(int i = 0; i < n; ++i)
        end[i] = i + 1;

    while(start != end){
        output(end);
        end = p[end];
    }
    output(start);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    vector<int> v(n);
    for(int &x: v) cin >> x;
    bfs(v);
}