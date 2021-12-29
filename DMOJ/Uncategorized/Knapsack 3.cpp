#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 5000;
int N, M; ll dp[MM+5];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N >> M;
    for (int i=1, n, v, p; i<=N; i++) {
        cin >> n >> v >> p;
        for (int j=1; j<=n; j<<=1) {
            for (int k=MM; k>=1ll*j*v; k--) dp[k] = max(dp[k], dp[k-j*v] + 1ll*j*p);
            n -= j;
        }
        if (!n) continue;
        for (int k=MM; k>=1ll*n*v; k--) dp[k] = max(dp[k], dp[k-n*v] + 1ll*n*p);
    }
    ll ans = -1e18;
    for (int i=1, c, f; i<=M; i++) {
        cin >> c >> f;
        ans = max(ans, dp[c] - f);
    }
    printf("%lld\n", ans);
}