#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define nl '\n'

const int MOD = 1e9 + 7;
int n, x, pos;

void solve(int tc) {

    cin >> n >> x >> pos;
    int lo = 0, hi = n, small = 0, big = 0;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (mid <= pos) {
            if (mid < pos) small++;
            lo = mid + 1;
        }
        else big++, hi = mid;
    }
    if (lo - 1 != pos || small > x || big > n - x) { cout << 0 << nl; return; }
    ll ans = 1;
    for (int i = x - 1; i >= x - small; i--) ans = (ans * 1LL * i) % MOD;
    for (int i = n - x; i > n - x - big; i--) ans = (ans * 1LL * i) % MOD;
    for (int i = n - small - big - 1; i >= 1; i--) ans = (ans * 1LL * i) % MOD;
    cout << ans % MOD << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}