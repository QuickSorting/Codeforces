#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }
#define all(x) (x).begin(), (x).end()

const int N = 1e6 + 3;
//ull!!!!!!!!!!!!!!!!!!!

struct Fenwick{

} f;

int n;
ll a[N];
vector<int> idx[64];
int l[N], r[N];

ll find_cnt_pairs(int col){
    vector<array<ll, 3>> sweepline;
    for(int i: idx[col]){
        sweepline.push_back({i, 1, r[i]});
        //sweepline.push_back({r[i], 2, i});
        sweepline.push_back({l[i], 3, i});
        sweepline.push_back({i, 0, l[i]});
    }
    sort(all(sweepline));

    ull ans = 0;
    for(auto p: sweepline){
        if(p[1] == 1){
            int i = p[0];
            ans += cnt.query(i + 1, r[i] - 1) * r[i] * i;
            ans += sum_lj.query(i + 1, r[i] - 1);
            ans -= i * sum_j.query(i + 1, r[i] - 1);
            ans -= r[i] * sum_l.query(i + 1, r[i] - 1);
        }
        else if(p[1] == 3){
            int j = p[0];
            cnt.update(j, 1);
            sum_lj.update(j, j * l[j]);
            sum_j.update(j, j);
            sum_l.update(j, l[j]);
        }
        else{
            int j = p[0];
            cnt.update(j, -1);
            sum_lj.update(j, -j * l[j]);
            sum_j.update(j, -j);
            sum_l.update(j, -l[j]);
        }
    }
}

void build_l_r(){
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];

    for(int i = 1; i <= n; ++i)
        idx[__builtin_popcount(a[i])].push_back(i);

    build_l_r();

    ll ans = 0;
    for(int i = 0; i < 64; ++i)
        ans += find_cnt_pairs(i);

    cout << ans << "\n";
}