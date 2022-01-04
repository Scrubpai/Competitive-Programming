#include <bits/stdc++.h>
using namespace std;
#define nl '\n'

const int MM = 1e4 + 5;
int N; double dp[MM], p[MM];

void solve(int tc) {

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> p[i]; dp[i] = dp[i-1] + p[i];
        if (i >= 2) dp[i] = min(dp[i], dp[i-2] + 1.0*min(p[i], p[i-1])/2 + 1.0*max(p[i], p[i-1]));
        if (i >= 3) { double v = min({p[i], p[i-1], p[i-2]}); dp[i] = min(dp[i], dp[i-3] + p[i-2] + p[i-1] + p[i] - v); }
    }
    printf("%.1f", dp[N]);

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}