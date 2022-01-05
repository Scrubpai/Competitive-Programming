#include <bits/stdc++.h>
using namespace std;
const int MM = 2e4+5;
#define nl '\n'
int n, dp[2][2], l[MM], r[MM];
void solve(int tc) {
    cin >> n >> l[0] >> r[0]; n--;
    dp[0][0] = r[0]-1+(r[0]-l[0]); dp[0][1] = r[0]-1;
    for (int i = 1; i <= n; i++) {
        cin >> l[i] >> r[i];
        int idx = i&1;
        dp[idx][0] = min(dp[idx^1][0]+abs(r[i]-l[i-1]), dp[idx^1][1]+abs(r[i]-r[i-1]))+r[i]-l[i];
        dp[idx][1] = min(dp[idx^1][0]+abs(l[i]-l[i-1]), dp[idx^1][1]+abs(l[i]-r[i-1]))+r[i]-l[i];
    }
    cout << min(dp[n&1][0]+n-l[n]+1, dp[n&1][1]+n-r[n]+1)+n << nl;
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); int tc = 1; /*cin >> tc; */ for (int t = 1; t <= tc; t++) solve(t); return 0; }