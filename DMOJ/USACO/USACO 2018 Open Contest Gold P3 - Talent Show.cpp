#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define nl '\n'
#define INF 0x3f3f3f3f
int N, W, w[255], t[255], dp[250005];
void solve(int tc) {
    cin >> N >> W;
    int sum = 0;
    for (int i = 1; i <= N; i++) {
        cin >> w[i] >> t[i];
        sum += t[i];
    }
    memset(dp, INF, sizeof(dp)); dp[0] = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = sum; j >= t[i]; j--) {
            dp[j] = min(dp[j], dp[j-t[i]] + w[i]);
        }
    }
    double ans = 0;
    for (int i = 1; i <= sum; i++) {
        if (dp[i] == INF || dp[i] < W) continue;
        ans = max(ans, 1.0*i/dp[i]);
    }
    cout << (ll)(1000*ans) << nl;
}
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}