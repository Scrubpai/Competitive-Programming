#include <bits/stdc++.h>
using namespace std;
const int MM = 1<<21, mod = 1e9+7;
int N, a[22][22], dp[MM];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N; dp[0] = 1;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cin >> a[i][j];
        }
    }
    for (int mask=0; mask<(1<<N)-1; mask++) {
        int m = __builtin_popcount(mask);
        for (int j=0; j<N; j++) {
            if (!(mask&(1<<j)) && a[m][j]) dp[mask|(1<<j)] = (dp[mask|(1<<j)] + dp[mask]) % mod;
        }
    }
    printf("%d\n", dp[(1<<N)-1]);
}