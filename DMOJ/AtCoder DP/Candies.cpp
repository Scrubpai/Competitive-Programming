#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+5, mod=1e9+7;
int N, K, a[105], dp[105][MM];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N >> K;
    for (int i=1; i<=K+1; i++) dp[0][i] = 1;
    for (int i=1; i<=N; i++) {
        cin >> a[i];
        dp[i][1] = 1;
        for (int j=2; j<=K+1; j++) {
            dp[i][j] = ((dp[i-1][j] - dp[i-1][max(j-a[i]-1, 0)]) % mod + mod) % mod;
            dp[i][j] = (dp[i][j] + dp[i][j-1]) % mod;
        }
    }
    printf("%d\n", (dp[N][K+1] - dp[N][K] + mod) % mod);
}