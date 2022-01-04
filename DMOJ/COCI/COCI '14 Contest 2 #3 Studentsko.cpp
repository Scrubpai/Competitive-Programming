#include <bits/stdc++.h>
using namespace std;
#define nl '\n'

int n, k, v[5005], v2[5005], dp[5005];

void solve(int tc) {

    cin >> n >> k;
    for (int i = 1; i <= n; i++) { cin >> v[i]; v2[i] = v[i]; }
    sort(v2 + 1, v2 + 1 + n);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int idx = lower_bound(v2 + 1, v2 + 1 + n, v[i]) - (v2 + 1) + 1;
        v[i] = idx / k + 1;
        if (idx % k == 0) v[i]--;
        for (int j = v[i]; j >= 1; j--) dp[v[i]] = max(dp[v[i]], dp[j] + 1);
        ans = max(ans, dp[v[i]]);
    }
    cout << n - ans << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}