#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5;
int N, W, dp[MM+1];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N >> W; memset(dp, 0x3f, sizeof(dp)); dp[0] = 0;
    for (int i=1, w, v; i<=N; i++) {
        cin >> w >> v;
        for (int j=MM; j>=v; j--) dp[j] = min(dp[j], dp[j-v]+w);
    }
    for (int i=MM; i; i--) {
        if (dp[i]<=W) {
            printf("%d\n", i);
            return 0;
        }
    }
}