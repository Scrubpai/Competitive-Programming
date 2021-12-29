#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N, a[405]; ll psa[405], dp[405][405];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N;
    for (int i=1; i<=N; i++) { cin >> a[i]; psa[i] = psa[i-1] + a[i]; }
    for (int len=2; len<=N; len++) {
        for (int l=1; l+len-1<=N; l++) {
            int r = l+len-1; dp[l][r] = 1e18;
            for (int k=l; k<r; k++) {
                dp[l][r] = min(dp[l][r], dp[l][k] + dp[k+1][r] + psa[r] - psa[l-1]);
            }
        }
    }
    printf("%lld\n", dp[1][N]);
}