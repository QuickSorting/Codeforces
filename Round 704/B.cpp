#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vector<int> p(n + 1);
        for(int i = 1; i <= n; ++i)
            cin >> p[i];

        stack<int> pos;
        for(int i = 1; i <= n; ++i)
            if(pos.empty() || p[i] > p[pos.top()])
                pos.push(i);

        int r = n;
        while(!pos.empty()){
            for(int i = pos.top(); i <= r; ++i)
                cout << p[i] << " ";
            r = pos.top() - 1;
            pos.pop();
        }
        cout << "\n";
    }
}