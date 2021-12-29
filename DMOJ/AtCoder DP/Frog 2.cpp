#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+5;
int N, K, h[MM], dp[MM];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N >> K >> h[1]; memset(dp, 0x3f, sizeof(dp)); dp[1] = 0;
    for (int i=2; i<=N; i++) {
        cin >> h[i];
        for (int j=i-1; j>=1 && j>=i-K; j--) dp[i] = min(dp[i], dp[j] + abs(h[i]-h[j]));
    }
    printf("%d\n", dp[N]);
}