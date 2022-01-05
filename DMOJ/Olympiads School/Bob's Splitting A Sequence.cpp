#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e5 + 5;
#define nl '\n'
int N, a[MM]; ll psa[MM];
void solve(int tc) {
    cin >> N;
    for (int i = 1; i <= N; i++) { cin >> a[i]; psa[i] = psa[i-1] + a[i]; }
    ll ans = 1e18;
    for (int L = 2; L < N; L++) {
        int lo = L, hi = N - 1, R = N-1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (psa[mid] - psa[L-1] >= (psa[N] - psa[L-1]) / 2) R = min(R, mid), hi = mid - 1;
            else lo = mid + 1;
        }
        ans = min(ans, max({psa[L-1], psa[R] - psa[L-1], psa[N] - psa[R]}) - min({psa[L-1], psa[R] - psa[L-1], psa[N] - psa[R]}));
        if (R > L) { R--; ans = min(ans, max({psa[L-1], psa[R] - psa[L-1], psa[N] - psa[R]}) - min({psa[L-1], psa[R] - psa[L-1], psa[N] - psa[R]})); }
    }
    cout << ans << nl;
}
int32_t main() {
    //freopen("", "r", stdin); freopen("", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}