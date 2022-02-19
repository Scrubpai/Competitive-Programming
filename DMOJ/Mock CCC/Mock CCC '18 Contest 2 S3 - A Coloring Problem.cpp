/* Idea:

We can think think of the blue squares as making up a histogram
For example, for sample input 2, the starting grid would be:
    B B B B B B
    B B B B B B
    B B B B R R
    B B B B R R
    B B B B R R
    . R R R R R
    . R R R R R

Then the histogram would be like this, with heights (hb[i]): {5, 5, 5, 5, 2, 2}
    x x x x x x
    x x x x x x
    x x x x
    x x x x
    x x x x

Basically, observe that the heights are always non-increasing.

Also, observe that the red squares, form a similar histogram (that's not upside-down) where the heights (let's call them hr[i]) are non-decreasing

So we can let dp[i][j] be the number of possible colorings for the first i columns such that the i-th column has j blue squares (basically grid[1][i] to grid[j][i] are all blue)
    so for all j from hb[i] to hr[i]-1, dp[i][j] can transition from all dp[i-1][height that's >= j] since the histogram of blue squares is non-increasing

    so dp[i][j] = dp[i-1][j] + dp[i-1][j+1] + ... + dp[i-1][m]

    We can optimize this to O(nm) using 1D PSA
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int m, n, mxb[31], mnr[31]; char g[31][31]; ll dp[31][31];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> m >> n;
    for (int i=1; i<=m; i++) {
        for (int j=1; j<=n; j++) {
            cin >> g[i][j];
            if (g[i][j] == 'B') {
                mxb[j] = i;
            }
        }
    }
    for (int j=n-1; j>=1; j--) {
        mxb[j] = max(mxb[j], mxb[j+1]);
        for (int i=1; i<=mxb[j]; i++) {
            if (g[i][j] == 'R') {
                cout << 0 << '\n';
                return 0;
            }
        }
    }
    mnr[0] = 1e9;
    for (int j=1; j<=n; j++) {
        mnr[j] = 1e9;
        for (int i=mxb[j]+1; i<=m; i++) {
            if (g[i][j] == 'R') {
                mnr[j] = i;
                break;
            }
        }
        mnr[j] = min(mnr[j], mnr[j-1]);
    }
    for (int j=1; j<=n; j++) {
        for (int i=0; i<=m; i++) {
            if (i<mnr[j] && i>=mxb[j]) {
                if (j == 1) dp[j][i] = 1;
                else {
                    dp[j][i] = dp[j-1][m];
                    if (i) dp[j][i] -= dp[j-1][i-1];
                }
            }
            if (i) dp[j][i] += dp[j][i-1];
        }
    }
    cout << dp[n][m] << '\n';
}