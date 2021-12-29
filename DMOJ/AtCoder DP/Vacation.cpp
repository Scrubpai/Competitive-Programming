#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+5;
int N, dp[MM][3];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N;
    for (int i=1, a, b, c; i<=N; i++) {
        cin >> a >> b >> c;
        dp[i][0] = max(dp[i-1][1], dp[i-1][2]) + a;
        dp[i][1] = max(dp[i-1][0], dp[i-1][2]) + b;
        dp[i][2] = max(dp[i-1][0], dp[i-1][1]) + c;
    }
    printf("%d\n", max({dp[N][0], dp[N][1], dp[N][2]}));
}