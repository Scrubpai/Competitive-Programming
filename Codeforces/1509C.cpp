#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 2005;
#define nl '\n'
int n, s[MM]; ll dp[MM][MM];
void solve(int tc) {
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> s[i];
        for (int j=1; j<=n; j++) dp[i][j]=1e18;
        dp[i][i]=0;
    }
    sort(s+1, s+1+n);
    for (int k=2; k<=n; k++) {
        for (int i=1; i+k-1<=n; i++) {
            int j=i+k-1;
            dp[i][j] = min(dp[i+1][j] + s[j] - s[i], dp[i][j-1] + s[j] - s[i]);
        }
    }
    cout << dp[1][n] << nl;
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); int tc = 1; /*cin >> tc;*/ for (int t = 1; t <= tc; t++) solve(t); return 0; }