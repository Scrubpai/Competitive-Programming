#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define nl '\n'
#define ms(x, y) memset(x, y, sizeof(x))
#define LL_INF 0x3f3f3f3f3f3f3f3f

string a, b; ll n, m, dp[5005][5005];

void solve(int tc) {

    cin >> n >> m >> a >> b; a = " " + a; b = " " + b;
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i] == b[j]) dp[i][j] = max({0ll, 4+dp[i-1][j-1]-2});
            dp[i][j] = max({dp[i][j], dp[i-1][j]-1, dp[i][j-1]-1, 0ll});
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int tc = 1;// cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}