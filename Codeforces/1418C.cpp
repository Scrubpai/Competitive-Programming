#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
#define INF 0x3f3f3f3f

const int MM = 2e5 + 5;
int n, a[MM], dp[MM][2];

void solve(int tc) {

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    dp[0][0] = dp[1][1] = INF; dp[1][0] = a[1];
    for (int i = 2; i <= n; i++) {
        //I kill ith boss
        dp[i][1] = min(dp[i-1][0], dp[i-2][0]);
        //friend kills ith boss
        dp[i][0] = min(dp[i-1][1] + a[i], dp[i-2][1] + a[i-1] + a[i]);
    }
    cout << min(dp[n][0], dp[n][1]) << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int tc = 1; cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}