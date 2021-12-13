#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll N = 50 + 3;
const ll CNT = 100;
const ll ITER = 21;
const ll INF = 1e18;

mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());
template<class T, class T1> bool check_min(T &x, const T1 &y) { return x > y ? x = y, true : false; }
template<class T, class T1> bool check_max(T &x, const T1 &y) { return x < y ? x = y, true : false; }

ll n, k, l[N], r[N], c[N];
ll a[N], curr_score, ans;
ll perm[N];

array<ll, 3> dp[N][4];

ll get_cost(ll xor_){
    ll cost = 0;
    for(ll i = 0; i < k; ++i)
        if((xor_ >> i) & 1)
            cost += c[i];
    return cost;
}

ll rnd(ll mod){
    return mt() % mod;
}

void update(int i, int state, int state_next, int mv, ll *p){
    if(!i) check_min(dp[i][state], array{p[mv], (ll)mv, (ll)-1});
    else check_min(dp[i][state], array{dp[i - 1][state_next][0] + p[mv], (ll)mv, (ll)state_next});
}

ll solve(ll pos, ll *arr){
    cout << "solve " << pos << endl;
    for(int i = 0; i <= k - 1; ++i){
        bool l_bit = (l[pos] >> i) & 1;
        bool r_bit = (r[pos] >> i) & 1;

        ll p[2];
        if(arr[i] == 2) p[0] = p[1] = c[i]; 
        else{
            p[0] = (arr[i] != 0) * 2 * c[i];
            p[1] = (arr[i] != 1) * 2 * c[i];
        }

        for(int j = 0; j < 4; ++j){
            dp[i][j] = {INF, INF, INF};
            bool l_equal = (j >> 0) & 1;
            bool r_equal = (j >> 1) & 1;

            
        }

        if(!l_bit){
            update(i, 0, 0, 0, p);
            update(i, 0, 3, 1, p);
        }
        else
            update(i, 0, 0, 1, p);

        if(r_bit){
            update(i, 1, 1, 1, p);
            update(i, 1, 3, 0, p);
        }
        else
            update(i, 1, 1, 0, p);

        if(l_bit == r_bit)
            update(i, 2, 2, l_bit, p);
        else{
            update(i, 2, 0, 0, p);
            update(i, 2, 1, 1, p);
        }

        update(i, 3, 3, 0, p);
        update(i, 3, 3, 1, p);
    }

    ll ans = 0;
    int i = k - 1, state = 2;
    while(i > 0){
        ll mv = dp[i][state][1];
        ll next_state = dp[i][state][2];
        ans += mv * (1ll << i);

        --i, state = next_state;
    }

    return ans;
}

void improve(){
    for(ll i = 0; i < ITER; ++i){
        for(ll j = 0; j < n; ++j)
            perm[j] = j;
        random_shuffle(perm, perm + n, rnd);

        for(ll i2 = 0; i2 < n; ++i2){
            ll x = perm[i2];

            vector<ll> adj;
            if(x) adj.push_back(a[x - 1]);
            if(x != n - 1) adj.push_back(a[x + 1]);

            static ll arr[N];
            for(int i = 0; i < k; ++i){
                if(adj.size() == 1) arr[i] = (adj[0] >> i) & 1;
                else{
                    bool l_bit = (adj[0] >> i) & 1;
                    bool r_bit = (adj[1] >> i) & 1;
                    if(l_bit != r_bit) arr[i] = 2;
                    else arr[i] = l_bit;
                }
            }

            for(ll val: adj)
                curr_score -= get_cost(a[x] ^ val);

            a[x] = solve(x, arr);

            for(ll val: adj)
                curr_score += get_cost(a[x] ^ val);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    for(ll i = 0; i < n; ++i)
        cin >> l[i] >> r[i];
    for(ll i = 0; i < k; ++i)
        cin >> c[i];

    ans = INF;
    for(ll i = 0; i < CNT; ++i){
        curr_score = 0;
        for(ll j = 0; j < n; ++j)
            a[j] = mt() % (r[j] - l[j] + 1) + l[j];
        for(ll j = 0; j < n - 1; ++j)
            curr_score += get_cost(a[j] ^ a[j + 1]);

        improve();
        ans = min(ans, curr_score);
    }

    cout << ans << "\n";
}