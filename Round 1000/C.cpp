#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }
#define all(x) (x).begin(), (x).end()

pair<int, int> merge(pair<int, int> l, pair<int, int> r){
    return {l.first, r.second};
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        int n, q;
        cin >> n >> q;

        set<pair<int, int>> s[2];
        for(int i = 0; i < q; ++i){
            int t;
            cin >> t;

            if(!t){
                int l, r, x;
                cin >> l >> r >> x;

                if(!x){
                    s[0].insert({l, r});
                    auto it = s[0].find({l, r});
                    while(it != s[0].begin()){
                        auto it_before = it;
                        --it_before;
                        if(it_before->second >= l){
                            auto new_p = merge(*it_before, {l, r});
                            s[0].erase(it_before);
                            s[0].erase(it);
                            s[0].insert(new_p);
                            l = new_p.first;
                            r = new_p.second;

                            it = s[0].find(new_p);
                        }
                        else break;
                    }

                    it = s[0].find({l, r});
                    while(it != --s[0].end()){
                        auto it_after = it;
                        ++it_after;
                        if(it_after->first <= r){
                            auto new_p = merge({l, r}, it_after);
                            s[0].erase(it_after);
                            s[0].erase(it);
                            s[0].insert(new_p);
                            l = new_p.first;
                            r = new_p.second;

                            it = s[0].find(new_p);
                        }
                    }

                    s[1].insert({l, r});
                    it = s[1].find({l, r});

                    if(it != s[1].begin()){
                        auto it_before = it;
                        --it_before;
                        if(it_before->second >= l){
                            auto p = *it_before;
                            s[1].erase(p);
                            s[1].insert({p.first, l - 1});   
                        }
                    }

                    it = s[1].find({l, r});
                    while(it != --s[1].end()){
                        auto it_after = it;
                        ++it_after;
                        if(it_after->first <= r){
                            auto p = *it_after;
                            s[1].erase(p);
                            s[1].insert({r + 1, p.second});
                        }
                    }

                    s[1].erase({l, r});
                }
                else{
                    s[1].insert({l, r});
                    if()
                }
            }
        }
    }
}
