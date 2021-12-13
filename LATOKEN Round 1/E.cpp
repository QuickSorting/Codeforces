#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template<class T> void check_min(T &a, const T b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T b){ a = (a > b) ? a : b; }

const int N = 500 + 3;

int n, k, ans = 0;

int query(const vector<int> &v){
    cout << "? ";
    for(int x: v)
        cout << x + 1 << " ";
    cout << "\n";
    cout.flush();
    int ret;
    for(int x: v)
        ret ^= x + 1;
    return ret;
}

void answer(int x){
    cout << "! " << x << "\n";
    cout.flush();
    exit(0);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    if((n & 1) && k % 2 == 0){
        cout << "-1\n";
        cout.flush();
        return 0;
    }
    if(k > n){
        cout << "-1\n";
        cout.flush();
        return 0;
    }

    int first = 0;
    for(int i = 0; i < n / k; ++i){
        vector<int> v;
        for(int j = i * k; j < (i + 1) * k; ++j)
            v.push_back(j);
        ans ^= query(v);
        if(i == 0) first = ans;
    }

    int rem = n % k;
    if(rem % 2 == 0){
        if(!rem){
            answer(ans);
            return 0;
        }
        vector<int> v;
        for(int i = 0; i < k - (rem >> 1); ++i)
            v.push_back(i);
        for(int i = (n / k) * k; i < (n / k) * k + (rem >> 1); ++i)
            v.push_back(i);
        ans ^= query(v);
        v.clear();
        for(int i = 0; i < k - (rem >> 1); ++i)
            v.push_back(i);
        for(int i = (n / k) * k + (rem >> 1); i < n; ++i)
            v.push_back(i);
        ans ^= query(v);
        answer(ans);
        return 0;
    }
    for(int j = 2; j <= k - rem; j += 2){
        if((k - rem) % j) continue;
        if((j + 1) * (k - rem) / j <= (n / k) * k){
            int sz = (k - rem) / j;
            for(int i1 = 0; i1 < j + 1; ++i1){
                vector<int> v;
                for(int i2 = 0; i2 < j + 1; ++i2){
                    if(i1 == i2) continue;
                    for(int i3 = i2 * sz; i3 < (i2 + 1) * sz; ++i3)
                        v.push_back(i3);
                }
                for(int i2 = n - rem; i2 < n; ++i2)
                    v.push_back(i2);
                ans ^= query(v);
            }
            answer(ans);
            return 0;
        }
    }
}