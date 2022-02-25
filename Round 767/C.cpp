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
        int mat[4][4]{}, mat2[4][4];
        for(int state = 0; state < (1 << 16); ++state){
            for(int i = 0; i < 4; ++i)
                for(int j = 0; j < 4; ++j)
                    mat[i][j] = (state >> (i * 4 + j)) & 1;

            bool ok = true;
            for(int i = 0; i < 4; ++i){
                for(int j = 0; j < 4; ++j){
                    array<int, 2> adj[4]{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
                    int curr = 0;
                    for(auto [di, dj]: adj){
                        auto [to_i, to_j] = pair{di + i, dj + j};
                        if(0 <= to_i && to_i <= 3 && 0 <= to_j && to_j <= 3){
                            curr += mat[to_i][to_j];
                        }
                    }
                    mat2[i][j] = curr & 1;
                    if(!mat2[i][j]){
                        ok = false;
                        break;
                    }
                }
            }

            if(ok){
                cout << "---------------------" << endl;
                for(int i = 0; i < 4; ++i){
                    for(int j = 0; j < 4; ++j)
                        cout << mat[i][j] << " ";
                    cout << "\n";
                }
            }
        }
    }
}