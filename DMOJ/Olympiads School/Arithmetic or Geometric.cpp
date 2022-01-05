#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define nl '\n'

const int MOD = 1e9 + 7;
ll pwmd(ll b, ll exp) {
    ll ret = 1;
    while (exp > 0) {
        if (exp % 2 == 1) ret = (ret * b) % MOD;
        exp /= 2;
        b = (b * b) % MOD;
    }
    return ret;
}
ll a1, a2, a3, k;

void solve(int tc) {

    cin >> a1 >> a2 >> a3 >> k;
    if (a2 - a1 == a3 - a2) {
        cout << (1LL * a1 + (k - 1) * (a2 - a1) % MOD) % MOD  << nl;
    } else {
        ll r = a2 / a1;
        cout << a1 * pwmd(r, k - 1) % MOD << nl;
    }

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int tc = 1; cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}