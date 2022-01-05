#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define nl '\n'
#define INF 0x3f3f3f3f3f3f3f3f
int N; ll dp[5005];
void solve(int tc) {
    cin >> N;
    memset(dp, INF, sizeof(dp)); dp[0] = 0;
    int sum = 0;
    for (int i = 1, v, p; i <= N; i++) {
        cin >> v >> p;
        sum += p;
        int val = 1+v/2;
        for (int j = 5000; j >= p; j--) {
            dp[j] = min(dp[j], dp[j-p] + val);
        }
    }
    ll ans = INF;
    for (int i = 1+sum/2; i <= sum; i++) ans = min(ans, dp[i]);
    cout << ans << nl;
}
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}