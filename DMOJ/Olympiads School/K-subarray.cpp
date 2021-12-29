#include <bits/stdc++.h>
using namespace std;
const int MM = 2e4+5;
int N, K, a[MM], psa[MM], dp[2][MM], mx[2][MM], pre, cur=1;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N >> K; memset(dp, -0x3f, sizeof(dp)); memset(mx, -0x3f, sizeof(mx)); dp[0][0] = mx[0][0] = 0;
    for (int i=1; i<=N; i++) { cin >> a[i]; psa[i] = psa[i-1] + a[i]; }
    for (int i=1; i<=N; i++) {
        dp[cur][0] = 0;
        for (int j=1; j<=K; j++) dp[cur][j] = max(dp[pre][j], mx[pre][j-1] + psa[i]);
        for (int j=0; j<=K; j++) mx[cur][j] = max(mx[pre][j], dp[cur][j] - psa[i]);
        swap(pre, cur);
    }
    printf("%d\n", dp[pre][K]);
}