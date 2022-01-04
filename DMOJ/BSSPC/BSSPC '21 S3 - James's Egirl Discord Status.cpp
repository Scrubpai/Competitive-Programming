#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e6+5;
int N, K, a[MM]; ll dp[MM], psa[MM];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N >> K;
    ll ans = 0;
    for (int i=1; i<=N; i++) {
        cin >> a[i];
        psa[i] = psa[i-1] + a[i];
        if (i >= K) {
            dp[i] = max(0ll, dp[i-K]) + psa[i] - psa[i-K];
        }
        ans = max(ans, dp[i]);
    }
    printf("%lld\n", ans);
}