#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e5 + 3;
const int INF = 1e9;

int n, m, x[N], y[N], a[N], b[N], d = 0;
vector<int> idx[2 * N];
bool ans[N];
set<pair<int, int>> s;
set<array<int, 3>> xs, ys, ms;
    
array<int, 3> get_min(int target, int &mn){
    int which = -1;
    mn = INF;
    if(!xs.empty() && (*xs.begin())[0] < mn){
        mn = (*xs.begin())[0];
        which = 0;
    }
    if(!ys.empty() && (*ys.begin())[0] - d < mn){
        mn = (*ys.begin())[0];
        which = 1;
    }
    if(!ms.empty() && (*ms.begin())[0] < mn){
        mn = (*ms.begin())[0];
        which = 2;
    }

    if(mn > target) return {-1, -1, -1};

    array<int, 3> ans;
    if(which == 0){
        ans = *xs.begin();
        xs.erase(ans);
    }
    else if(which == 1){
        ans = *ys.begin();
        ys.erase(ans);
    }
    else{
        ans = *ms.begin();
        ms.erase(ans);
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i = 0; i < n; ++i)
        cin >> x[i] >> y[i];
    for(int i = 0; i < m; ++i)
        cin >> a[i] >> b[i];

    for(int i = 0; i < n; ++i){
        idx[y[i] - x[i] + N].push_back(i);
        s.insert({x[i], y[i]});
        if(y[i] - x[i] > 0)
            ys.insert({y[i], i, 0});
        else if(y[i] - x[i] < 0)
            xs.insert({x[i], i, 0});
        else
            ms.insert({x[i], i, 0});
    }

    for(int i = 0; i < m; ++i){
        if(s.count({a[i], b[i]}) || (!a[i] && !b[i]))
            ans[i] = 0;
        else{
            if(b[i] - a[i] > 0)
                ys.insert({b[i], i, 1});
            else if(b[i] - a[i] < 0)
                xs.insert({a[i], i, 1});
            else
                ms.insert({a[i], i, 1});
        }
    }

    while(!xs.empty() && !ys.empty() && !ms.empty()){
        bool losing = true;
        int mn, t;
        vector<array<int, 3>> v;

        v.push_back(get_min(INF, mn));
        while(true){
            array<int, 3> arr = get_min(mn, t);
            if(t != mn) break;
            v.push_back(arr);
        }

        for(auto arr: v)
            if(!arr[2])
                losing = false;

        for(auto arr: v){
            if(arr[2]){
                if(losing && b[arr[1]] - a[arr[1]] == d)
                    ans[arr[1]] = false;
                else
                    ans[arr[1]] = true;
            }
        }


    }
}