#include <bits/stdc++.h>
using namespace std;
const int MM = 100;
int N, M, dp[105];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N >> M; memset(dp, -0x3f, sizeof(dp)); dp[0]=0;
    for (int i=1, x, y, b, s; i<=N; i++) {
        cin >> x >> y >> b >> s;
        for (int j=1; j<=y; j<<=1) {
            for (int k=0; k+j<=MM; k++) dp[k] = max(dp[k], dp[k+j] + s*j);
            y-=j;
        }
        for (int k=0; k+y<=MM; k++) dp[k] = max(dp[k], dp[k+y] + s*y);
        for (int j=1; j<=x; j<<=1) {
            for (int k=MM; k>=j; k--) dp[k] = max(dp[k], dp[k-j] - b*j);
            x-=j;
        }
        for (int k=MM; k>=x; k--) dp[k] = max(dp[k], dp[k-x] - b*x);
        for (int k=0; k<=MM; k++) dp[k] -= k*M;
    }
    cout << dp[0] << '\n';
}