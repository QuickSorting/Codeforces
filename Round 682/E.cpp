#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e5 + 3;
const int LOG_N = 30;

int a[N], n;
ll prefix[N];

ll get_sum(int l, int r){
    if(!l) return prefix[r];
    return prefix[r] - prefix[l - 1];
}

bool check(int l, int r){
    //cout << "check " << l << " " << r << endl; 
    if(r - l + 1 < 3) return false;
    if(get_sum(l + 1, r - 1) != (a[l] ^ a[r])) return false;
    return true;
}

int solve(int l, int r){
    if(r - l + 1 < 3) return 0;
    //cout << "solve " << l << " " << r << endl; 

    int mx = 0;
    for(int i = l; i <= r; ++i)
        mx = max(mx, a[i]);

    int bit = LOG_N - 1;
    while(!((mx >> bit) & 1)) bit--;

    vector<int> pos;
    for(int i = l; i <= r; ++i)
        if((a[i] >> bit) & 1)
            pos.push_back(i);

    int ans = 0;
    for(int i = 0; i < (int)pos.size() - 1; ++i)
        ans += check(pos[i], pos[i + 1]);

    for(int i = 0; i < (int)pos.size(); ++i){
        int from;
        int to;

        if(i) from = pos[i - 1] + 1;
        else from = l;

        if(i != (int)pos.size() - 1) to = pos[i + 1] - 1;
        else to = r;

        for(int j = from; j <= to; ++j){
            if(j == pos[i]) continue;
            if(j < pos[i]) ans += check(j, pos[i]);
            else ans += check(pos[i], j);
        }
    }

    for(int i = 0; i < (int)pos.size(); ++i){
        if(i){
            int to;
            if(i != (int)pos.size() - 1) to = pos[i + 1] - 1;
            else to = r;

            for(int j = pos[i] + 1; j <= to; ++j)
                ans += check(pos[i - 1], j);
        }
        if(i != (int)pos.size() - 1){
            int to;
            if(i) to = pos[i - 1] + 1;
            else to = l;

            for(int j = pos[i] - 1; j >= to; --j)
                ans += check(j, pos[i + 1]);
        }
    }

    pos.insert(pos.begin(), l - 1);
    pos.push_back(r + 1);
    for(int i = 0; i < (int)pos.size() - 1; ++i)
        ans += solve(pos[i] + 1, pos[i + 1] - 1);

    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for(int i = 0; i < n; ++i)
        cin >> a[i];

    prefix[0] = a[0];
    for(int i = 1; i < n; ++i)
        prefix[i] = prefix[i - 1] + a[i];

    cout << solve(0, n - 1) << "\n";
}