#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }
#define all(x) (x).begin(), (x).end()

const ll N = 2e5 + 3;

ll n, m, a[N];
ll *teachers;
vector<ll> b[N];

struct Fraction{
    int i, idx;
    ll up, down;

    Fraction(){}
    Fraction(ll up, ll down = 1): up(up), down(down){}
    friend bool operator>(const Fraction &l, const Fraction &r){
        return l.up * r.down > r.up * l.down;
    }
    friend bool operator<(const Fraction &l, const Fraction &r){
        return l.up * r.down < r.up * l.down;
    }
};

Fraction avg[N];
int normal[N], plus1[N], minus1[N];

int get_normal(int l, int r){
    if(l > r) return 0;
    if(!l) return normal[r];
    return normal[r] - normal[l - 1];
}
int get_plus1(int l, int r){
    if(l > r) return 0;
    if(!l) return plus1[r];
    return plus1[r] - plus1[l - 1];
}
int get_minus1(int l, int r){
    if(l > r) return 0;
    if(!l) return minus1[r];
    return minus1[r] - minus1[l - 1];
}

void init(){
    for(int i = 0; i < n; ++i){
        if(i) normal[i] = normal[i - 1];
        else normal[i] = 0;

        normal[i] += avg[i] > Fraction(teachers[i]);
    }

    for(int i = 0; i < n; ++i){
        if(i) plus1[i] = plus1[i - 1];
        else plus1[i] = 0;

        if(i != n - 1) plus1[i] += avg[i] > Fraction(teachers[i + 1]);
        else plus1[i] += 1;
    }

    for(int i = 0; i < n; ++i){
        if(i) minus1[i] = minus1[i - 1];
        else minus1[i] = 0;

        if(i != 0) minus1[i] += avg[i] > Fraction(teachers[i - 1]);
        else minus1[i] += 1;
    }
}

void solve(){
    cin >> n >> m;
    for(ll i = 0; i < n; ++i)
        cin >> a[i];
    ll idx = 0;
    for(ll i = 0; i < m; ++i){
        ll k;
        cin >> k;
        b[i].resize(k);

        avg[i].up = 0;
        for(ll j = 0; j < k; ++j){
            cin >> b[i][j];
            avg[i].up += b[i][j];
        }
        avg[i].down = k;
        avg[i].idx = idx;
        avg[i].i = i;
        idx += k;
    }

    sort(a, a + n);
    teachers = a + n - m;

    sort(avg, avg + m);

    init();

    string ans(idx, '0');
    for(int i = 0; i < m; ++i){
        vector<ll> &curr_b = b[avg[i].i];
        ll idx = avg[i].idx;

        Fraction new_avg;
        for(int j = 0; j < curr_b.size(); ++j){
            new_avg = avg[i];
            new_avg.up -= curr_b[j];
            new_avg.down--;

            // cout << new_avg.up << " " << new_avg.down << " new_avg\n";

            int l = 0, r = m;
            while(l != r){
                int mid = (l + r) >> 1;
                if(new_avg > teachers[mid])
                    l = mid + 1;
                else r = mid;
            }

            // cout << r << " pos" << endl;

            int pos = r;
            if(pos == m)
                continue;
        
            if(pos < i){
                if(!get_normal(0, pos - 1) && !get_plus1(pos, i - 1) && !get_normal(i + 1, m - 1)){
                    //cout << "sdsads" << endl;
                    ans[idx + j] = '1';
                } 
            }
            else{
                if(!get_normal(0, i - 1) && !get_minus1(i + 1, pos) && !get_normal(pos + 1, m - 1)){
                    //cout << "jhokdsdf" << endl;
                    ans[idx + j] = '1';
                }
            }
        }
    }

    cout << ans << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;

    while(t--)
        solve();
}