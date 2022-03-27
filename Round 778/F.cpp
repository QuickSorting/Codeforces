#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }
#define all(x) (x).begin(), (x).end()

const int N = (1 << 18) + 3;

int n;
string s, s2;

mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());

pair<int, bool> solve(int l, int r, int idx){
    if(l == r) return {0, true};

    int mid = (l + r) >> 1;
    int perm[2]{};
    bool matters[2]{};

    auto p1 = solve(l, mid, idx - 1);
    auto p2 = solve(mid + 1, r, idx - 1);

    perm[0] = p1.first;
    perm[1] = p2.first;
    matters[0] = p1.second;
    matters[1] = p2.second;

    int j = mid + 1;
    bool which = mt() & 1, eq = true;
    for(int i = l; i <= mid; ++i, ++j){
        if(s2[i] != s2[j]){
            if(s2[i] < s2[j]) which = 0;
            else which = 1;
            eq = false;
            break;
        }
    }

    int sz = (r - l + 1) / 2, start;
    if(!which) start = mid + 1;
    else start = l;

    for(int j = 0; j < sz; ++j)
        s2[start + j] = s[start + j]; 

    for(int i = 0; i < idx; ++i){
        int p = perm[which];
        if(i == idx - 1 && !matters[which])
            p = perm[!which];

        if((1 << i) & p){
            for(int j = 0; j < sz; ++j){
                if(start + j < start + (j ^ (1 << i)))
                swap(s2[start + j], s2[start + (j ^ (1 << i))]);
            }
        }
    }

    if(which){
        for(int i = 0; i < sz; ++i)
            swap(s2[l + i], s2[mid + 1 + i]);
    }

    int new_perm = perm[which];
    if(which)
        new_perm += 1 << idx;

    return {new_perm, eq};
}

clock_t timer = clock();

bool time_left(){
    return (((float)clock() - (float)timer) / (float)CLOCKS_PER_SEC) <= 2.5;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> s;
    string ans = s;

    while(time_left()){
        s2 = s;
        solve(0, (1 << n) - 1, n - 1);
        check_min(ans, s2);
    }

    cout << ans << "\n";
}