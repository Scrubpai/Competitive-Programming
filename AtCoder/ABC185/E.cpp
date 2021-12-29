#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
int N, M, A[1005], B[1005], dp[1005][1005];
void solve(int tc) {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) cin >> A[i];
    for (int i = 1; i <= M; i++) cin >> B[i];
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= M; j++) {
            if (i == 0 || j == 0) { dp[i][j] = i + j;  continue; }
            dp[i][j] = min(dp[i-1][j] + 1, dp[i][j-1] + 1);
            if (A[i] == B[j]) dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
            else dp[i][j] = min(dp[i][j], dp[i-1][j-1] + 1);
        }
    }
    cout << dp[N][M] << nl;
}
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}