#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define nl '\n'
int N, M, K, p[1005], s[1005]; ll dp[1005];
void solve(int tc) {
    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++) {
        cin >> p[i] >> s[i];
        for (int j = p[i]; j <= K; j++) {
            dp[j] = max(dp[j], dp[j-p[i]] + s[i]);
        }
    }
    for (int i = 1, q, t, d, a; i <= M; i++) {
        cin >> q >> t >> d >> a;
        for (int j = 1; a - j >= 0; j <<= 1) {
            ll cost = 1ll * j * d, value = 1ll * j * q * s[t];
            for (int k = K; k >= cost; k--) {
                dp[k] = max(dp[k], dp[k-cost] + value);
            }
            a -= j;
        }
        if (a) {
            ll cost = 1ll * a * d, value = 1ll * a * q * s[t];
            for (int k = K; k >= cost; k--) {
                dp[k] = max(dp[k], dp[k-cost] + value);
            }
        }
    }
    cout << dp[K] << nl;
}
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}