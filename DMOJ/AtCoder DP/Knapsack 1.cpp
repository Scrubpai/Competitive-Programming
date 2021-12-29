#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+5;
int N, W; long long dp[MM];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N >> W;
    for (int i=1, w, v; i<=N; i++) {
        cin >> w >> v;
        for (int j=W; j>=w; j--) dp[j] = max(dp[j], dp[j-w]+v);
    }
    printf("%lld\n", dp[W]);
}