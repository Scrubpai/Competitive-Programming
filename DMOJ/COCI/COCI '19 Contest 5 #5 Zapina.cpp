#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 355, mod = 1e9+7;
#define nl '\n'
int N; ll c[MM][MM], p[MM][MM], dp[MM][MM];
//dp[n][k]: # of assignments of k tasks to n programmers w/ at least one happy programmer, you have to assign all tasks
void solve(int tc) {
    cin >> N;
    for (int i=0; i<=N; i++) {
        for (int j=0; j<=i; j++) {
            if (j==0 || j==i) c[i][j] = 1;
            else c[i][j] = c[i-1][j-1] + c[i-1][j];
            c[i][j] %= mod;
        }
        p[i][0] = 1;
        for (int j=1; j<=N; j++) p[i][j] = p[i][j-1] * i % mod;
    }
    for (int n=1; n<=N; n++) {
        for (int k=1; k<=N; k++) {
            if (k >= n) dp[n][k] = c[k][n] * p[n-1][k-n] % mod; // case 1: make nth programmer happy
            for (int i=0; i<=k; i++) { //case 2: don't make nth programmer happy
                if (i==n) continue;
                dp[n][k] = (dp[n][k] + c[k][i] * dp[n-1][k-i] % mod) % mod;
            }
        }
    }
    cout << dp[N][N] << nl;
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int tc = 1; /*cin >> tc;*/ for (int t = 1; t <= tc; t++) solve(t); return 0; }