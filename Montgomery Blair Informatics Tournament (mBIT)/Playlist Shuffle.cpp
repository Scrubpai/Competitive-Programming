#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define nl '\n'
const ll INF = 1e18;

ll n, b; ld x, y;

//ld check(ll rad) {
//    ld l = max(1ll, b - rad), r = min(n, b + rad), radlft = b - l, radrit = r - b;
//    ld s = (radlft * (radlft + 1) / 2) +  (radrit * (radrit + 1) / 2) * x, m = radlft + radrit + 1;
//    ld e = s / m + (y * n) / m; //i think that it should be s + (y * n) / m, which is the proper calculation
//    ld res = (s + (n - m) * e) / n;
//    return res;
//}

ld check(ll rad){
    ld l = max(0LL, b-rad);
    ld r = min(n-1, b+rad);
    ld sum = ((b-l)*(b-l+1)/2 + (r-b)*(r-b+1)/2)/n*x;
    ld t = (y + sum)/(r-l+1);
    ld res = sum + (n-(r-l+1))*t;
    return res;
}

//ll ternary(ll l, ll r) {
//    if (abs(r - l) <= 4) {
//        ld mn = INF; ll idx = -1;
//        for (ll i = l; i <= r; i++) {
//            ld val = check(i);
//            if (check(i) < mn) mn = val, idx = i;
//        }
//        return idx;
//    }
//    ll m1 = (2 * l + r) / 3, m2 = (2 * r + l) / 3, c1 = check(m1), c2 = check(m2);
//    if (c1 < c2) return ternary(l, m2 - 1);
//    else return ternary(m1 + 1, r);
//}

int ternary(ll l, ll  r){
    if(abs(r - l) <= 4){
        ld mn = INF;
        ll idx = -1;
        for(ll i = l; i<=r; i++){
            ld val = check(i);
            if(val<mn){
                mn = val;
                idx = i;
            }
        }
        return idx;
    }
    ll m1 = (2*l + r)/3;
    ll m2 = (l + 2*r)/3;
    if(check(m1)<check(m2)) return ternary(l, m2-1);
    return ternary(m1+1, r);

}

void solve(int tc) {

    cin >> n >> b >> x >> y;
//    ll lo = 0, hi = max(b - 1, n - b); ll idx = ternary(lo, hi);
//    cout << setprecision(100) << check(idx) << nl;

    b--;
    int idx = ternary(0, max(b, n-1-b));
    cout << setprecision(100) << check(idx) << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}