#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 1e5 + 3;
const int MAX = 1000 + 3;

int n, d, a[N], curr = 1;
vector<int> v[10], ans, num;

pair<string, bool> dp[43][10];

string to_str_num(int x){
    if(x == 0) return "0";
    string ret = "";
    while(x > 0){
        ret += x % 10 + '0';
        x /= 10;
    }
    return ret;
}

void rem_zeroes(string &s){
    while(s.size() > 1 && s.back() == '0')
        s.pop_back();
}

string add(string s, string s2){
    string ret = "";
    int rem = 0;
    for(int i = 0; i < max(s.size(), s2.size()); ++i){
        if(i < s.size()) rem += s[i] - '0';
        if(i < s2.size()) rem += s2[i] - '0';
        if(rem >= 10){
            ret += (rem - 10) + '0';
            rem = 1;
        }
        else{
            ret += rem + '0';
            rem = 0;
        }
    }
    if(rem) ret += "1";
    rem_zeroes(ret);
    return ret;
}

string multiply(string s, string s2){
    string ret = "0";
    for(int i = 0; i < s2.size(); ++i){
        for(int j = 0; j < (s2[i] - '0'); ++j) ret = add(ret, s);
        s.insert(0, "0");
    }
    rem_zeroes(ret);
    return ret;
}

bool compare(string l, string r){
    if(l.size() != r.size()) return l.size() < r.size();
    for(int i = (int)l.size() - 1; i >= 0; --i)
        if(l[i] != r[i])
            return l[i] < r[i];
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> d;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        v[a[i] % 10].push_back(a[i]);
    }
    for(int i = 0; i < 10; ++i)
        sort(v[i].begin(), v[i].end(), greater<int>());

    if(d == 0){

        curr = 1;
        for(int i = 0; i < n; ++i)
            if(a[i]){
                ans.push_back(a[i]);
                curr *= a[i];
                curr %= 10;
            }
        if(!curr){
            cout << ans.size() << "\n";
            for(int x: ans)
                cout << x << " ";
            cout << endl;
            return 0;
        }

        curr = 1;
        ans.clear();
        for(int i = 0; i < n; ++i){
            ans.push_back(a[i]);
            curr *= a[i];
            curr %= 10;
        }
        if(!curr){
            cout << ans.size() << "\n";
            for(int x: ans)
                cout << x << " ";
            cout << endl;
            return 0;
        }
        cout << "-1\n";
        return 0;
    }

    for(int i = 1; i < 10; ++i){
        if(i == 5){
            if(d % 5 == 0){
                for(int x: v[i])
                    ans.push_back(x);
            }
        }
        else if(i % 2 == 0){
            if(d % 2 == 0){
                for(int j = 0; j < (int)v[i].size() - 4; ++j)
                    ans.push_back(v[i][j]);
                for(int j = max(0, (int)v[i].size() - 4); j < v[i].size(); ++j)
                    num.push_back(v[i][j]);
            }
        }
        else{
            for(int j = 0; j < (int)v[i].size() - 4; ++j)
                ans.push_back(v[i][j]);
            for(int j = max(0, (int)v[i].size() - 4); j < v[i].size(); ++j)
                num.push_back(v[i][j]);
        }
    }

    curr = 1;
    for(int x: ans){
        curr *= x;
        curr %= 10;
    }

    for(int i = 0; i < 10; ++i)
        dp[num.size()][i] = {"0", false};
    dp[num.size()][d] = {"1", false};

    for(int i = (int)num.size() - 1; i >= 0; --i){
        for(int j = 0; j < 10; ++j){
            auto &[big, choice] = dp[i][j];
            big = "0";
            choice = false;
            string cand = multiply(dp[i + 1][j * num[i] % 10].first, to_str_num(num[i]));
            if(compare(big, cand)){
                big = cand;
                choice = true;
            }

            cand = dp[i + 1][j].first;
            if(compare(big, cand)){
                big = cand;
                choice = false;
            }
            //cout << big << " - " << i << " " << j << endl; 
        }
    }

    //tryabva da opravya sluchaya kogato ne vzemam nishto
    int i = 0, j = curr;
    while(i != num.size()){
        if(dp[i][j].second){
            ans.push_back(num[i]);
            curr *= num[i];
            curr %= 10;
            j = j * num[i] % 10;
            ++i;
        }
        else ++i;
    }

    if(ans.empty() || curr != d){
        cout << "-1\n";
        return 0;
    }

    cout << ans.size() << "\n";
    for(int x: ans)
        cout << x << " ";
    cout << '\n';
}
/*
10 6
1 2 3 4 5 6 7 8 9 10
*/