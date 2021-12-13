#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define all(x) (x).begin(), (x).end()

const int N = 1e4 + 3;

int n;
int a[N];

void solve(){
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];

    if(a[n] == 0){
        for(int i = 1; i <= n + 1; ++i)
            cout << i << " ";
        cout << "\n";
    }
    else{
        bool ok = false;
        for(int i = 1; i <= n - 1; ++i)
            if(!a[i] && a[i + 1]){
                ok = true;
                for(int j = 1; j <= i; ++j)
                    cout << j << " ";
                cout << n + 1 << " ";
                for(int j = i + 1; j <= n; ++j)
                    cout << j << " ";
                cout << "\n";
                break;
            }
        if(!ok){
            cout << n + 1 << " ";
            for(int i = 1; i <= n; ++i)
                cout << i << " ";
            cout << "\n";
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--) solve();
}