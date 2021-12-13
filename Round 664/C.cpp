#include <bits/stdc++.h>

using namespace std;

const int k_N = 3e5 + 3;

int n;
string s[k_N];
pair<int, int> p[k_N];

pair<bool, pair<int, int>> check(int mid){
    for(int i = 0; i < n; ++i){
        array<pair<int, int>, 6> v;
        auto [x, y] = p[i];
        v[0] = {x - mid, y - mid};
        v[1] = {x - mid, y};
        v[2] = {x + mid, y};
        v[3] = {x, y - mid};
        v[4] = {x, y + mid};
        v[5] = {x + mid, y + mid};

        for(auto [x2, y2]: v){
            bool ok = true;
            for(int j = 0; j < n; ++j){
                auto [x3, y3] =  p[j];

                if((x2 < x3) != (y2 != y3)){
                    if(abs(x2 - x3) + abs(y2 - y3) > mid){
                        ok = false;
                        break;
                    }
                }
                else{
                    if(max(abs(x2 - x3), abs(y2 - y3)) > mid){
                        ok = false;
                        break;
                    }
                }
            }

            if(ok = true) return {true, {x2, y2}};
        }
    }   

    return {false, {-1, -1}};
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for(int i = 0; i < n; ++i){
        cin >> s[i];
        int cnt_b = 0, cnt_n = 0;
        for(char c: s[i]){
            if(c == 'B') cnt_b++;
            else cnt_n++;
        }

        p[i] = {cnt_b, cnt_n};
    }

    int l = 0, r = 4 * k_N;
    while(l != r){
        int mid = (l + r) >> 1;
        if(check(mid).first) r = mid;
        else l = mid + 1;
    }

    cout << l << "\n";
    pair<int, int> ans = check(l).second;
    for(int i = 0; i < ans.first; ++i)
        cout << "B";
    for(int i = 0; i < ans.second; ++i)
        cout << "N";
    cout << "\n";
}