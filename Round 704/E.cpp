#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 25e4 + 3;

int n, m;
vector<vector<int>> v;
int cnt[N], ans[N];

bool add(int i, int val, int add_val){
    bool ok = true;
    for(int j = 0; j < n; ++j)
        if(v[j][i] != val){
            cnt[j] += add_val;
            if(cnt[j] > 2) ok = false;
        }
    return ok;
}

void output_ans(){
    cout << "Yes\n";
    for(int i = 0; i < m; ++i)
        cout << ans[i] << " ";
    cout << "\n";
    exit(0);
}

void try_element(int x){
    bool ok = true;
    ans[x] = -1;
    for(int i = 0; i < n; ++i)
        if(cnt[i] == 2){
            if(ans[x] == -1) ans[x] = v[i][x];
            else ok = false;
        }

    if(ans[x] == -1)
        ans[x] = 1;
    if(ok) output_ans();
}

void try_array(int l, int r){
    fill(cnt, cnt + n, 0);

    for(int i = l; i <= r; ++i){
        ans[i] = v[0][i];
        if(!add(i, v[0][i], 1)) return;
    }

    vector<int> nxt;
    for(int i = 0; i < l; ++i) nxt.push_back(i);
    for(int i = r + 1; i < m; ++i) nxt.push_back(i);

    for(int i = 0; i < n; ++i){
        if(cnt[i] == 2){
            ans[nxt[0]] = v[i][nxt[0]];
            ans[nxt[1]] = v[i][nxt[1]];
            if(!add(nxt[0], v[i][nxt[0]], 1)) return;
            if(!add(nxt[1], v[i][nxt[1]], 1)) return;
            output_ans();
        }
    }

    for(int i = 0; i < n; ++i){
        if(cnt[i] == 1){
            ans[nxt[0]] = v[i][nxt[0]];
            if(add(nxt[0], v[i][nxt[0]], 1))
                try_element(nxt[1]);
            add(nxt[0], v[i][nxt[0]], -1);
            ans[nxt[1]] = v[i][nxt[1]];
            if(!add(nxt[1], v[i][nxt[1]], 1)) return;
            try_element(nxt[0]);
            return;
        }
    }

    ans[nxt[0]] = 1;
    ans[nxt[1]] = 1;
    output_ans();
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    v.resize(n, vector<int>(m, 0));
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            cin >> v[i][j];

    if(m <= 2){
        cout << "Yes\n";
        for(int i = 1; i <= m; ++i)
            cout << "1 ";
        cout << "\n";
        return 0;
    }

    try_array(0, m - 3);
    try_array(1, m - 2);
    try_array(2, m - 1);

    cout << "No\n";
}