#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }
#define all(x) (x).begin(), (x).end()

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        int n, a, b;
        cin >> n >> a >> b;
    
        int mx1 = (n - 2) / 2 + (n & 1);
        int mx2 = (n - 2) / 2;

        if(abs(a - b) > 1){
            cout << "-1\n";
            continue;           
        }
        if(max(a, b) > mx1 || min(a, b) > mx2){
            cout << "-1\n";
            continue;
        }

        bool a_bigger = (a >= b);

        int a_l = n - a + 1, a_r = n;
        int b_l = 1, b_r = b;
        int mid_l = b + 1, mid_r = n - a;
        
        for(int i = 0; i < n; ++i){
            if(i == 0){
                cout << mid_l++ << " ";
                continue;
            }

            if((i & 1) != a_bigger){
                if(b_l > b_r)
                    cout << mid_l++ << " ";
                else
                    cout << b_l++ << " ";
            }
            else{
                if(a_l > a_r)
                    cout << mid_l++ << " ";
                else
                    cout << a_l++ << " ";
            }
        }
        cout << "\n";
    }
}