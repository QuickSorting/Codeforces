#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }
#define all(x) (x).begin(), (x).end()

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    double best = 1;
    ll mx = 2e8;
    int best_m, best_iter;
    for(ll m = 4; m <= 25; ++m){
        for(ll iter = 1; iter <= 1000; ++iter){
            ll curr = ((1ll << m) * m + 500000) * iter;
            if(curr > mx) continue;
            double cand = 1.0 - pow((double)(m - 5) / (double)m, 5); 
            cand = pow(cand, iter);
            if(cand < best){
                best = cand;
                best_m = m;
                best_iter = iter;
                cout << pow(1 - best, 100) << " " << best_m << " " << best_iter << endl;
            }
        }
    }
}