#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+5;
int N, K, dp[MM], a[105];
int fun(int k) {
    if (k == 0) return 0;
    if (dp[k] != -1) return dp[k];
    dp[k] = 0;
    for (int i=1; i<=N; i++) {
        if (k-a[i]>=0) dp[k] = max(dp[k], fun(k-a[i]) ^ 1);
    }
    return dp[k];
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N >> K; memset(dp, -1, sizeof(dp));
    for (int i=1; i<=N; i++) cin >> a[i];
    printf("%s\n", fun(K)?"First":"Second");
}