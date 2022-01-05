#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define nl '\n'
#define ms(x, y) memset(x, y, sizeof(x))

int N, L, X[205], T[205]; ll dp[205][205][205][2];

void solve(int tc) {

    cin >> N >> L;  X[N+1] = 0; //start (0)
    //instead of using dp[l][r] as dp[405][405] (shifting the array X[i] = X[i+N+1]), use dp[205][205] --> go left how many steps, go right how many steps
    for (int i = 1; i <= N; i++) cin >> X[i];
    for (int i = 1; i <= N; i++) cin >> T[i];
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= N; j++) {
            for (int k = 0; k <= N; k++) {
                dp[i][j][k][0] = dp[i][j][k][1] = 1e18;
            }
        }
    }
    dp[0][0][0][0] = dp[0][0][0][1] = dp[N+1][0][0][0] = dp[N+1][0][0][1] = dp[0][N+1][0][0] = dp[0][N+1][0][1] = 0;
    for (int k = 1; k <= N; k++) {
        for (int l = 0; l <= N; l++) {
            int r = k - l;
            if (r<0) continue;
            for (int st = 0; st <= N; st++) {
                if (l>0 && dp[l-1][r][st][0] + (X[N-l+2] - X[N-l+1] + L) % L <= T[N-l+1]) dp[l][r][st+1][0] = min(dp[l][r][st+1][0], dp[l-1][r][st][0] + (X[N-l+2] - X[N-l+1] + L) % L);
                else if (l>0) dp[l][r][st][0] = min(dp[l][r][st][0], dp[l-1][r][st][0] + (X[N-l+2] - X[N-l+1] + L) % L);
                if (l>0 && dp[l-1][r][st][1] + (X[r] - X[N-l+1] + L) % L <= T[N-l+1]) dp[l][r][st+1][0] = min(dp[l][r][st+1][0], dp[l-1][r][st][1] + (X[r] - X[N-l+1] + L) % L);
                else if (l>0) dp[l][r][st][0] = min(dp[l][r][st][0], dp[l-1][r][st][1] + (X[r] - X[N-l+1] + L) % L);
                if (r>0 && dp[l][r-1][st][0] + (X[r] - X[N-l+1] + L) % L <= T[r]) dp[l][r][st+1][1] = min(dp[l][r][st+1][1], dp[l][r-1][st][0] + (X[r] - X[N-l+1] + L) % L);
                else if (r>0) dp[l][r][st][1] = min(dp[l][r][st][1], dp[l][r-1][st][0] + (X[r] - X[N-l+1] + L) % L);
                if (r>0 && dp[l][r-1][st][1] + (X[r] - X[r-1] + L) % L <= T[r]) dp[l][r][st+1][1] = min(dp[l][r][st+1][1], dp[l][r-1][st][1] + (X[r] - X[r-1] + L) % L);
                else if (r>0) dp[l][r][st][1] = min(dp[l][r][st][1], dp[l][r-1][st][1] + (X[r] - X[r-1] + L) % L);
            }
        }
    }
    int ans = 0;
    for (int l = 0; l <= N; l++) {
        for (int st = 1; st <= N; st++) {
            if (dp[l][N-l][st][0] < 1e18 || dp[l][N-l][st][1] < 1e18) ans = max(ans, st);
        }
    }
    cout << ans << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}