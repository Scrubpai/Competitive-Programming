#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
#define ms(x, y) memset(x, y, sizeof(x))
#define INF 0x3f3f3f3f

int n, dp[1005], h[1005];

void solve(int tc) {

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> h[i];
    ms(dp, INF); dp[1] = 1;
    for (int i = 1; i <= n; i++) {
        double mx = -INF;
        for (int j = i + 1; j <= n; j++) {
            if (1.0 * ((1.0 * h[j] - h[i]) / (j - i) >= mx)) {
                dp[j] = min(dp[j], dp[i] + 1);
                mx = 1.0 * ((1.0 * h[j] - h[i]) / (j - i));
            }
        }
    }
    cout << dp[n] << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}