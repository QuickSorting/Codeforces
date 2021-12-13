#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 1e5 + 5;

ll n, s, p[N], d[N], g[N];

bool check(ll k){
    for(int i = 1; i <= n; ++i){
        p[i] = 0;
        d[i] = 0;
        g[i] = 0;
    }

    d[1] = 1;
    ll i = 1, ind = 1, sum = 1;
    while(i <= n){
        ll t = ind;
        ind = i;

        p[i] = t;
        g[t]++;

        d[i] = d[t] + 1;
        sum += d[i];
        i++;

        if(g[t] == k) t++;

        while(i <= n && t < ind && sum + d[t] + 1 + )
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> s;

    int l = 0, r = n + 1;
    while(l != r){
        int mid = (l + r + 1) >> 1;
        if(check(mid)) l = mid;
        else r = mid - 1;
    }

    if(l == n + 1){
        cout << "No\n";
        return 0;
    }

    cout << "Yes\n";
    check(l);

    for(int i = 2; i <= n; ++i)
        cout << p[i] << " ";
    cout << "\n";
}