#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
#define ms(x, y) memset(x, y, sizeof(x))
#define INF 0x3f3f3f3f

int N, M, K, p[505], b[505], dp[505][505];

void solve(int tc) {

    cin >> N >> M >> K;
    ms(dp, -INF); dp[0][0] = 0;
    //dp[i][j]: max pts if I give j cards to the first i teams
    for (int i = 1; i <= N; i++) cin >> p[i];
    for (int i = 0; i <= M; i++) cin >> b[i];
    for (int i = 1; i <= N; i++) {
        dp[i][0] = dp[i-1][0] + b[p[i]];
        for (int j = 0; j <= min(K, M - p[i]); j++) {
            for (int k = j; k <= K; k++) {
                dp[i][k] = max(dp[i][k], dp[i-1][k-j] + b[p[i]+j]);
            }
        }
    }
    cout << dp[N][K] << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}