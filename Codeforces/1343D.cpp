#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5 + 5;
#define nl '\n'
int n, k, a[MM], psa[2*MM];
void solve(int tc) {
    cin >> n >> k;
    memset(psa, 0, sizeof(psa));
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n / 2; i++) {
        int lo = min(a[i], a[n-i+1]) + 1, hi = max(a[i], a[n-i+1]) + k;
        // [lo, sum) += 1; (sum, hi] += 1; [2, lo) += 2; (hi, 2*k] += 2
        psa[lo]++; psa[a[i]+a[n-i+1]]--; psa[a[i]+a[n-i+1]+1]++; psa[hi+1]--; psa[2] += 2; psa[lo] -= 2; psa[hi+1] += 2;
    }
    int ans = 1e9;
    for (int i = 2; i <= 2*k; i++) {
        psa[i] += psa[i-1];
        ans = min(ans, psa[i]);
    }
    cout << ans << nl;
}
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc = 1; cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}