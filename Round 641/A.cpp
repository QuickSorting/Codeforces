#include <bits/stdc++.h>

using namespace std;

const int k_N = 1e5 + 7;
const int k_Val = 2e5 + 7;

long long a[k_N];
vector<int> primes[k_Val];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for(int i = 0; i < n; ++i)
        cin >> a[i];

    if(n == 2){
        cout << a[0] * a[1] / __gcd(a[0], a[1]) << "\n";
        return 0;
    }

    for(int i = 0; i < n; ++i){
        for(int d = 2; d * d <= a[i]; ++d){
            if(a[i] % d == 0){
                int power = 1;
                while(a[i] % d == 0){
                    a[i] /= d;
                    power *= d;
                }
                primes[d].push_back(power);
            }
        }

        if(a[i] != 1)
            primes[a[i]].push_back(a[i]);
    }

    long long answer = 1;
    for(int i = 2; i < k_Val; ++i){
        if(primes[i].size() < n - 1)
            continue;
        if(primes[i].size() == n - 1)
            primes[i].push_back(1);

        int min1 = k_Val, min2 = k_Val;
        for(int x: primes[i]){
            if(x <= min1){
                min2 = min1;
                min1 = x;
            }
            else
                if(x <= min2)
                    min2 = x;
        }

        answer *= min2;
    }

    cout << answer << "\n";
}