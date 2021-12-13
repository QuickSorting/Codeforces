#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        ll p, f;
        cin >> p >> f;

        ll cnt_s, cnt_w;
        cin >> cnt_s >> cnt_w;

        ll s, w;
        cin >> s >> w;

        if(s > w){
            swap(s, w);
            swap(cnt_s, cnt_w);
        }

        ll ans = 0;
        for(ll i = 0; i <= cnt_s; ++i){
            if(i * s > p) break;
            ll p_rem = p - i * s;
            ll f_rem = f;
            ll curr_ans = i;

            ll curr_s = cnt_s - i;
            ll curr_w = cnt_w;

            if(p_rem / w > curr_w){
                curr_ans += curr_w;
                curr_w = 0;
            }
            else{
                curr_ans += p_rem / w;
                curr_w -= p_rem / w;
            }

            if(f_rem / s > curr_s){
                curr_ans += curr_s;
                f_rem -= curr_s * s;

                if(f_rem / w > curr_w)
                    curr_ans += curr_w;
                else
                    curr_ans += f_rem / w;
            }
            else
                curr_ans += f_rem / s;

            ans = max(ans, curr_ans);
        }

        cout << ans << "\n";
    }
}