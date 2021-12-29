#include <bits/stdc++.h>
using namespace std;
#define ms(x, y) memset(x, y, sizeof(x))
int n, k[205], dp[205][205];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    while (true) {
        scanf("%d", &n);
        if (!n) return 0;
        ms(dp, 0);
        for (int i=1; i<=n; i++) scanf("%d", &k[i]);
        for (int len=3; len<=n; len++) {
            for (int l=1; l+len-1<=n; l++) {
                int r = l+len-1;
                for (int m=l+1; m<r; m++) {
                    dp[l][r] = max(dp[l][r], k[l] + k[m] + k[r] + dp[l][m] + dp[m][r]);
                }
            }
        }
        printf("%d\n", dp[1][n]);
    }
}