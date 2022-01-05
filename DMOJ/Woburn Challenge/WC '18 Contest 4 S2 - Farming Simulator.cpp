#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define nl '\n'
#define fi first
#define se second
#define INF 0x3f3f3f3f3f3f3f3f
int N, H; pii a[3005]; ll dp[3005];
void solve(int tc) {
    cin >> N >> H;
    for (int i = 1, p, w; i <= N; i++) {
        cin >> p >> w;
        a[i] = {p, w};
    }
    sort(a + 1, a + 1 + N);
    //dp[i]: minimum time to COLLECT all seeds (after planted) in range [1, i]
    //Assume all seeds have been planted. Add H to final answer so only worry about Waiting and not planting. (if there is no Wait element, answer is always H)
    //dp[i] = dp[j] + (collect continuous interval of seeds [j, i])
    //For each seed that has been planted in [j, i], it will take a max of 2*(i-j) seconds to reach it
    /*
     * [      seed        ]
     *            ------->
     *  <-----------------
     *  ------->
     */
    //to collect all the seeds in [j, i] answer is either 2*(i-j) or max wait time in [j, i]
    memset(dp, INF, sizeof(dp)); dp[0] = 0;
    for (int i = 1; i <= N; i++) {
        ll mx = 0;
        for (int j = i; j >= 1; j--) {
            mx = max(mx, 1ll*a[j].se);
            dp[i] = min(dp[i], dp[j-1] + max(mx, 1ll*2*(a[i].fi - a[j].fi)));
        }
    }
    cout << dp[N] + H << nl;
}
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}