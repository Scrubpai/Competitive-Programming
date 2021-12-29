#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+5;
int N, dp[MM], h[MM];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N >> h[1] >> h[2]; dp[1] = 0; dp[2] = abs(h[2]-h[1]);
    for (int i=3; i<=N; i++) {
        cin >> h[i];
        dp[i] = min(dp[i-1] + abs(h[i]-h[i-1]), dp[i-2] + abs(h[i]-h[i-2]));
    }
    printf("%d\n", dp[N]);
}