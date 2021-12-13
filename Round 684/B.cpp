#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll N = 1e5 + 3;
const ll C = 1000 + 3;

vector<ll> adj[N];
ll n, m, k, d[N];
vector<ll> v;
bool b[C][C];

void remove(ll x, ll k2){
    for(ll to: adj[x]){
        d[to]--;
        if(d[to] == k2 - 1)
            v.push_back(to);
    }
}

bool try_solve(ll x){
    vector<ll> adj_x;
    for(ll to: adj[x]){
        if(d[to] < k - 1) continue;
        adj_x.push_back(to);
    }
    adj_x.push_back(x);

    for(int i = 0; i < adj_x.size(); ++i){
        for(int j = i + 1; j < adj_x.size(); ++j){
            if()
        }
    }
}

void solve(){
    cin >> n >> m >> k;
    for(ll i = 1; i <= n; ++i)
        adj[i].clear();

    for(ll i = 0; i < m; ++i){
        ll u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    v.clear();
    for(ll i = 1; i <= n; ++i){
        d[i] = adj[i].size();
        if(d[i] < k)
            v.push_back(i);
    }

    while(!v.empty()){
        ll x = v.back();
        v.pop_back();

        remove(x, k);
    }

    vector<ll> ans;
    for(ll i = 1; i <= n; ++i)
        if(d[i] >= k)
            ans.push_back(i);

    if(!ans.empty()){
        cout << "1 " << ans.size() << '\n';
        for(ll x: ans)
            cout << x << " ";
        cout << "\n";
        return;
    }

    if(k * (k - 1ll) / 2ll >= m){
        cout << "-1\n";
        return;
    }

    v.clear();
    for(ll i = 1; i <= n; ++i){
        d[i] = adj[i].size();
        if(d[i] < k - 1)
            v.push_back(i);
    }

    while(!v.empty()){
        ll x = v.back();
        v.pop_back();

        remove(x, k - 1);
    }

    ans.clear();
    for(ll i = 1; i <= n; ++i)
        if(d[i] >= k - 1)
            ans.push_back(i);

    for()

    while(!ans.empty()){
        for(int x: ans){
            if(d[x] == k - 1){
                if(try_solve(x))
                    break;
            }
        }
    }

    if(ans.empty()) cout << "-1\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;

    while(t--)
        solve();
}