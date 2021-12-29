#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
int H, W, dp[1005][1005]; char c;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> H >> W; dp[1][1] = 1;
    for (int i=1; i<=H; i++) {
        for (int j=1; j<=W; j++) {
            cin >> c;
            if (c != '#' && (i!=1 || j!=1)) dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % mod;
        }
    }
    printf("%d\n", dp[H][W]);
}