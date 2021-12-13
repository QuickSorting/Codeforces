#include <bits/stdc++.h>

using namespace std;

int n;
string l, r;

string rem_zeros(string x){
    int cnt = 0;
    for(int i = 0; i < x.size(); ++i){
        if(x[i] == '1') break;
        ++cnt;
    }
    if(cnt == x.size()) return "0";
    x.erase(0, cnt);
    return x;
}

string str_xor(string l, string r){
    string ret = "";
    for(int i = 0; i < n; ++i)
        ret += '0' + ((l[i] - '0') ^ (r[i] - '0'));
    return rem_zeros(ret);
}

string min1(string ret){
    for(int i = (int)ret.size() - 1; i >= 0; --i){
        if(ret[i] == '0')
            ret[i] = '1';
        else{
            ret[i] = '0';
            break;
        }
    }
    return ret;
}

string plus1(string ret){
    for(int i = (int)ret.size() - 1; i >= 0; --i){
        if(ret[i] == '1') ret[i] = '0';
        else{
            ret[i] = '1';
            break;
        }
    }
    return ret;
}

int cmp(const string &l, const string &r){
    if(l.size() != r.size()) return l.size() < r.size() ? -1 : 1;
    for(int i = 0; i < l.size(); ++i)
        if(l[i] != r[i])
            return l[i] < r[i] ? -1 : 1;
    return 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    cin >> l >> r;

    if(n == 1){
        cout << r << "\n";
        return 0;
    }
    if(l == r){
        cout << l << "\n";
        return 0;
    }

    for(int i = 0; i < n; ++i){
        if(l[i] != r[i]){
            if(!i){
                for(int j = 0; j < n; ++j)
                    cout << "1";
                cout << "\n";
                return 0;
            }
            if(r[n - 1] == '1'){
                cout << r << "\n";
                return 0;
            }
            if(r[n - 2] == '0'){
                while(l != r){
                    if(l[n - 1] == '0' && l[n - 2] == '1'){
                        r.pop_back();
                        cout << r << "1\n";
                        return 0; 
                    }
                    l = plus1(l);
                }
            }
            if(r[n - 2] == '1'){
                while(l != r){
                    if(l[n - 1] == '0' && l[n - 2] == '0'){
                        r.pop_back();
                        cout << r << "1\n";
                        return 0; 
                    }
                    l = plus1(l);
                }
            }
            cout << r << "\n";
            return 0;
        }
    }
}