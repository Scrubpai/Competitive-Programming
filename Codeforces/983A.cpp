#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define nl '\n'
ll gcd(ll a, ll b){return b == 0 ? a : gcd(b, a % b);}
ll p, q, b;
void solve(int tc) {
    cin >> p >> q >> b;
    if (p % q == 0) { cout << "Finite" << nl; return; }
    ll g = gcd(p, q); q /= g;
    while (gcd(b, q) != 1) {
        ll g = gcd(b, q);
        while (q % g == 0) q /= g;
    }
    if (q == 1) cout << "Finite" << nl;
    else cout << "Infinite" << nl;
}
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc = 1; cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}