#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
#define ms(x, y) memset(x, y, sizeof(x))
#define INF 0x3f3f3f3f

int n, ans, a[105], dp[105][105];

int fun(int l, int r, int cnt) {
    if (cnt > n) return 0;
    if (dp[l][r] != -1) return dp[l][r];
    return dp[l][r] = max((a[l]%2) - fun((l+1)%n, r, cnt+1), (a[r]%2) - fun(l, (r-1+n)%n, cnt+1));
}

void solve(int tc) {

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
        ms(dp, -1);
        int l = (i+1)%n, r = (i-1+n)%n;
        if ((a[i] % 2) - fun(l, r, 2) > 0) ans++;
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