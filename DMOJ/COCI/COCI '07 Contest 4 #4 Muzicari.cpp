#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
int T, N, mx, len[505], val[5005], pre[5005], ans[505]; bool dp[5005];
void solve(int tc) {
    cin >> T >> N; dp[0] = 1;
    for (int i = 1; i <= N; i++) {
        cin >> len[i];
        for (int j = T; j >= len[i]; j--) {
            if (dp[j]) { mx = max(mx, j); continue; }
            if (dp[j-len[i]]) dp[j] = 1, pre[j] = j - len[i], val[j] = i, mx = max(mx, j);
        }
    }
    for (int i = mx; i != 0; i = pre[i]) ans[val[i]] = i - len[val[i]], len[val[i]] = -1;
    int t = 0;
    for (int i = 1; i <= N; i++) {
        if (len[i] != -1) ans[i] = t, t += len[i];
        cout << ans[i] << " ";
    }
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); int tc = 1; /*cin >> tc; */ for (int t = 1; t <= tc; t++) solve(t); return 0; }