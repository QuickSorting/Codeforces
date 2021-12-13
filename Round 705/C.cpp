#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 3;
int n, k;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        cin >> n >> k;
        string s;
        cin >> s;

        if(n % k){
            cout << "-1\n";
            continue;
        }

        int cnt[26];
        fill(cnt, cnt + 26, 0);

        for(int i = 0; i < n; ++i)
            cnt[s[i] - 'a']++;

        bool ok = true;
        for(int i = 0; i < 26; ++i)
            if(cnt[i] % k)
                ok = false;

        if(ok){
            cout << s << "\n";
            continue;
        }

        fill(cnt, cnt + 26, 0);
        auto get_score = [&](int x){
            if(cnt[x] % k) return k - cnt[x] % k;
            return 0;
        };

        int prev_sum = 0, new_sum;
        int len = 0, letter;
        for(int i = 0; i < n; ++i){
            for(int j = s[i] - 'a' + 1; j <= 25; ++j){
                new_sum = prev_sum - get_score(j);
                cnt[j]++;
                new_sum += get_score(j);

                if(new_sum <= n - i - 1){
                    len = i;
                    letter = j;
                    cnt[j]--;
                    break;
                }
                else cnt[j]--;
            }
            prev_sum -= get_score(s[i] - 'a');
            cnt[s[i] - 'a']++;
            prev_sum += get_score(s[i] - 'a');
        }

        fill(cnt, cnt + 26, 0);
        prev_sum = 0;
        for(int i = 0; i < len; ++i){
            prev_sum -= get_score(s[i] - 'a');
            cnt[s[i] - 'a']++;
            prev_sum += get_score(s[i] - 'a');
            cout << s[i];
        }
        prev_sum -= get_score(letter);
        cnt[letter]++;
        prev_sum += get_score(letter);
        cout << (char)(letter + 'a');

        int t = n - len - 1 - prev_sum;
        for(int i = 0; i < t; ++i)
            cout << "a";
        for(int i = 0; i < 26; ++i)
            while(cnt[i] % k){
                cout << (char)(i + 'a');
                ++cnt[i];
            }
        cout << "\n";
    }
}