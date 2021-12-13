#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }

const int N = 50 + 3;
const int M = 5e4 + 3;
const int C = 300;

ll n, m;
set<pair<ll, ll>> s;

bool ok(ll x){
    auto it = s.lower_bound({x + 1, 0});
    if(it == s.begin()) return true;
    --it;
    if(it->first <= x && x <= it->second) return false;
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i = 0; i < m; ++i){
        string type;
        cin >> type;
        if(type == "block"){
            ll l, r;
            cin >> l >> r;
            s.insert({l, r});
        }
        else{
            set<ll> vis;
            ll a, b;
            cin >> a >> b;
            if(a == b){
                cout << "1\n";
                continue;
            }
            queue<ll> q;
            q.push(a);
            q.push(b);
            vis.insert(a);
            vis.insert(b);

            while(!q.empty()){
                ll u = q.front();
                q.pop();

                for(ll i = 0; i < n; ++i){
                    ll x = u ^ (1ll << i);
                    if(ok(x) && !vis.count(x)){
                        vis.insert(x);
                    }
                }
            }
        }
    }
}