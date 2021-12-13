#include <bits/stdc++.h>

using namespace std;

const int k_N = 1e5 + 7;

int n, k;
int a[k_N];
set<pair<int, int>> odd, even;

void solve(){
    cin >> n >> k;
    for(int i = 0; i < n; ++i)
        cin >> a[i];

    bool is_k_there = false;
    for(int i = 0; i < n && !is_k_there; ++i)
        if(a[i] == k)
            is_k_there = true;

    if(!is_k_there){
        cout << "no\n";
        return;
    }

    if(n == 1){
        cout << "yes\n";
        return;
    }

    for(int i = 0; i < n; ++i)
        a[i] = (a[i] >= k) ? 1 : -1;

    odd.clear();
    even.clear();

    odd.insert({0, -1});
    int curr_sum = 0;
    for(int i = 0; i < n; ++i){
        curr_sum += a[i];

        if(i % 2 == 0){
            auto it_odd = odd.begin();
            auto it_even = even.begin();

            if(it_odd != odd.end() && it_odd->second == i - 1)
                it_odd++;

            if(it_odd != odd.end() && curr_sum - it_odd->first >= 1){
                cout << "yes\n";
                return;
            }
            if(it_even != even.end() && curr_sum - it_even->first >= 2){
                cout << "yes\n";
                return;
            }

            even.insert({curr_sum, i});
        }
        else{
            auto it_odd = odd.begin();
            auto it_even = even.begin();

            if(it_even != even.end() && it_even->second == i - 1)
                it_even++;

            if(it_odd != odd.end() && curr_sum - it_odd->first >= 2){
                cout << "yes\n";
                return;
            }
            if(it_even != even.end() && curr_sum - it_even->first >= 1){
                cout << "yes\n";
                return;
            }

            odd.insert({curr_sum, i});
        }
    }

    cout << "no\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--)
        solve();
}