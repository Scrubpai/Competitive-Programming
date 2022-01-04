#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define nl '\n'
ll N, S;
void solve(int tc) {
    cin >> N >> S;
    ll tot = N * (N + 1) / 2;
    ll dif = tot - S;
    if (dif < 0) { cout << 0 << nl; return; }
    ll hi = (dif+1) / 2, lo = dif/2;
    if (dif % 2 == 0) hi++, lo--;
    cout << max(min(N - hi + 1, lo), 0ll) << nl;
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int tc = 1; cin >> tc; for (int t = 1; t <= tc; t++) solve(t); return 0; }