#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
int N, c[305], dp[305][305];
void solve(int tc) {
    cin >> N;
    for (int i=1; i<=N; i++) cin >> c[i];
    for (int k=2; k<=N; k++) {
        for (int l=1; l+k-1<=N; l++) {
            int r = l+k-1;
            if (c[l] == c[r]) dp[l][r] = dp[l+1][r-1] + 1;
            for (int i=l+1; i<r; i++) {
                dp[l][r] = max(dp[l][r], dp[l][i] + dp[i][r]);
            }
        }
    }
    cout << N - dp[1][N] << nl;
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int tc = 1; /*cin >> tc;*/ for (int t = 1; t <= tc; t++) solve(t); return 0; }