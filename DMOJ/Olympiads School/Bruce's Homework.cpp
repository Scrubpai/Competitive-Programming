#include <bits/stdc++.h>
using namespace std;
#define nl '\n'

const int MM = 8645;
int n, m, T, t[105], num[20005], vis[20005][105]; double dp[MM];

void solve(int tc) {

    cin >> n >> m >> T;
    int add = 0;
    for (int i = 1; i <= n; i++) cin >> t[i];
    for (int i = 1; i <= m; i++) {
        cin >> num[i];
        if (num[i] == 0) add++;
        for (int j = 1, p; j <= num[i]; j++) {
            cin >> p; vis[i][p] = 1;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (t[i] > T) continue;
        double add = 0.0;
        for (int j = 1; j <= m; j++) { if (num[j] == 0) continue; add += ((1.0 * vis[j][i]) / num[j]); };
        for (int j = T; j >= t[i]; j--) dp[j] = max(dp[j], dp[j-t[i]] + add);
    }
    dp[T] += add;
    printf("%.2f", dp[T]);

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}