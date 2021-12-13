#include <bits/stdc++.h>

using namespace std;

int mirror(int x){
    if(x == 0 || x == 1 || x == 8) return x;
    if(x == 2 || x == 5) return 7 - x;
    return -1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        int h, m;
        cin >> h >> m;
        string t;
        cin >> t;
        int hours = stoi(string(1, t[0]) + string(1, t[1]));
        int mins = stoi(string(1, t[3]) + string(1, t[4]));
        
        auto check = [&](int hours, int mins) -> bool{
            int new_hours = 0, new_mins = 0;
            int h1, h2, m1, m2;
            h1 = hours / 10, h2 = hours % 10;
            m1 = mins / 10, m2 = mins % 10;
            int nh1, nh2, nm1, nm2;
            nm2 = mirror(h1);
            nm1 = mirror(h2);
            nh2 = mirror(m1);
            nh1 = mirror(m2);
            if(nh1 == -1 || nh2 == -1 || nm1 == -1 || nm2 == -1) return false;
            new_hours = 10 * nh1 + nh2;
            new_mins = 10 * nm1 + nm2;
            if(new_hours >= h || new_mins >= m) return false;
            return true;
        };

        while(!check(hours, mins)){
            mins++;
            if(mins == m){
                hours++;
                mins = 0;
                if(hours == h) hours = 0;
            }
        }
        auto fo = [](int x) -> string{
            if(x / 10) return to_string(x);
            return "0" + to_string(x);
        };

        cout << fo(hours) << ":" << fo(mins) << "\n";
    }
}