#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define nl '\n'

const int MM = 1e5 + 5;
int n, k, a[MM]; ll dp[MM];

void solve (int tc) {

    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + 1 + n);
    ll ans = 0; stack<int> st;
    for (int i = 1; i <= n; i++) {
        dp[i] = a[i];
        if (a[i] - a[i-1] <= k) dp[i] += dp[i-1];
        ans = max(ans, dp[i]);
    }
    cout << ans;

}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}