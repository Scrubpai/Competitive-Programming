#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define nl '\n'
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll n, m, k;
void solve(int tc) {
    cin >> n >> m >> k;
    if (2 * n * m % k != 0) { cout << "NO" << nl; return; }
    ll base = n, height = m;
    ll g = gcd(n, k); base /= g; k /= g; g = gcd(m, k); height /= g; k /= g;
    if (k % 2 == 1) {
        if (base < n) base *= 2;
        else height *= 2;
    }
    cout << "YES" << nl << 0 << " " << 0 << nl << base << " " << 0 << nl << base << " " << height << nl;
}
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}