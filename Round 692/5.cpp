#include <bits/stdc++.h>
#pragma GCC optimize("O3")

using namespace std;

typedef long long ll;
const int N = 4e5 + 3;
const int MAX = 1e6 + 3;
const int X = 633;

int n, q, x, a[N], cnt[MAX];
array<int, 2> quer[N];

bool cmp(array<int, 2> l, array<int, 2> r){
    if(l[0] / X != r[0] / X)
        return l[0] < r[0];
    return l[1] > r[1];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> x;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];

    int q;
    cin >> q;
    ll xor_ans = 0;
    for(int i = 0; i < q; ++i)
        cin >> quer[i][0] >> quer[i][1];
    sort(quer, quer + q, cmp);

    int l = 1, r = 0;
    ll curr_ans = 0;
    for(int i = 0; i < q; ++i){
        for(; r < quer[i][1]; ++r){
            curr_ans += cnt[x - a[r + 1]];
            ++cnt[a[r + 1]];
        }
        for(; l > quer[i][0]; --l){
            curr_ans += cnt[x - a[l - 1]];
            ++cnt[a[l - 1]];
        }
        for(; r > quer[i][1]; --r){
            --cnt[a[r]];
            curr_ans -= cnt[x - a[r]];
        }
        for(; l < quer[i][0]; ++l){
            --cnt[a[l]];
            curr_ans -= cnt[x - a[l]];
        }
        xor_ans ^= curr_ans;
    }

    cout << xor_ans << "\n";
}