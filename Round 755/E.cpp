#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }
#define all(x) (x).begin(), (x).end()
#define x real()
#define y imag()
typedef long double ld;

const int N = 3000 + 3;
const int R = 1e5 + 3;

ll n, rad;
complex<ld> p[N];
bool ok_ray[N][N];

ld dot(complex<ld> a, complex<ld> b) {return a.x * b.x + a.y * b.y;}
ld cross(complex<ld> a, complex<ld> b) {return a.x * b.y - a.y * b.x;}

ld dist(complex<ld> a, complex<ld> b){
    return abs(a - b);
}

pair<complex<ld>, complex<ld>> circleIntersection(complex<ld> a, complex<ld> b){
    ld dx = b.x - a.x;
    ld dy = b.y - a.y;

    complex<ld> l = {b.x - dy, b.y + dx};
    complex<ld> r = {b.x + dy, b.y - dx};

    l = (l - b) * (ld)rad / dist(l, b) + b;
    r = (r - b) * (ld)rad / dist(r, b) + b;

    return {l, r};
}

ld orient(complex<ld> a, complex<ld> b, complex<ld> c){
    return cross(b - a, c - a);
}

bool insideAngle(complex<ld> o, complex<ld> l, complex<ld> r, complex<ld> p){
    return orient(o, r, p) >= 0 && orient(o, l, p) <= 0;
}

pair<complex<ld>, complex<ld>> intersectAngles(complex<ld> o, complex<ld> l1, complex<ld> r1, complex<ld> l2, complex<ld> r2){
    if(orient(o, l1, r1) > 0)
        return {l1, r1};

    if(insideAngle(o, l1, r1, l2)){
        if(insideAngle(o, l1, r1, r2))
            return {l2, r2};
        return {l2, r1};
    }
    if(insideAngle(o, l1, r1, r2))
        return {l1, r2};
    if(insideAngle(o, l2, r2, l1))
        return {l2, r2};
    return {r1, l1};
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> rad;
    for(int i = 0; i < n; ++i){
        ld x2, y2;
        cin >> x2 >> y2;
        p[i] = {x2, y2};
    }

    for(int i = 0; i < n; ++i){
        bool first = true;
        complex<ld> l, r;
        for(int j = 0; j < n; ++j){
            if(i == j) continue;
            if(dist(p[i], p[j]) <= rad) continue;

            auto [l2, r2] = circleIntersection(p[i], p[j]);
            if(first){    
                first = false;
                l = l2;
                r = r2;
                continue;
            }

            tie(l, r) = intersectAngles(p[i], l, r, l2, r2);
        }

        if(!first && orient(p[i], l, r) > 0)
            continue;

        for(int j = 0; j < n; ++j){
            if(i == j) continue;
            if(first){
                ok_ray[i][j] = true;
                continue;
            }
            ok_ray[i][j] =  insideAngle(p[i], l, r, p[j]);
        }
    }

    int ans = 0;
    for(int i = 0; i < n; ++i)
        for(int j = i + 1; j < n; ++j)
            ans += ok_ray[i][j] && ok_ray[j][i];

    cout << ans << "\n";
}