#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 3;
const int MOD = 1e9 + 7;

int a[N], n, q;
int big_p[N];
map<int, int> cnt[N];
multiset<int> ms[N];
long long ans = 1;

void euclid(){
    for(int i = 2; i < N; ++i){
        if(big_p[i]) continue;
        big_p[i] = i;
        for(int j = 2 * i; j < N; j += i)
            big_p[j] = i;
    }
}

int get_min(int prime){
    if(ms[prime].size() < n) return 0;
    return *ms[prime].begin();
}

void add_num(int x, int pos){
    while(x != 1){
        int prev_min = get_min(big_p[x]);

        if(cnt[pos][big_p[x]])
            ms[big_p[x]].erase(ms[big_p[x]].find(cnt[pos][big_p[x]]));
        cnt[pos][big_p[x]]++;
        ms[big_p[x]].insert(cnt[pos][big_p[x]]);

        int new_min = get_min(big_p[x]);
        if(new_min != prev_min) ans = ans * big_p[x] % MOD;

        x /= big_p[x];
    }
}

//special check for 1
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    euclid();

    cin >> n >> q;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        add_num(a[i], i);
    }
    for(int i = 0; i < q; ++i){
        int pos, x;
        cin >> pos >> x;
        --pos;
        add_num(x, pos);
        cout << ans << "\n";
    }
}