#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define nl '\n'

ll gcd(ll a, ll b){return b == 0 ? a : gcd(b, a % b);}
ll m, d, w;

void solve (int tc) {

    cin >> m >> d >> w;
    // (y - x) * (d - 1) mod w = 0 --> (y - x) * (d - 1) = kw for some integer k
    ll v = w / gcd(w, d - 1), mx = min(m, d);
    //y - x is a multiple of v
    //v * k < mx for integer k
    ll n = (mx - 1) / v, a1 = mx - v, an = a1 + (n - 1) * (-v);
    if (n <= 0) { cout << 0 << nl; return; }
    ll ans = (2 * an + (n - 1) * v) * n / 2;
    cout << ans << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc = 1; cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}