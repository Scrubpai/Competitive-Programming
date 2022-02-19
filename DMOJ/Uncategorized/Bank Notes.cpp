#include <bits/stdc++.h>
using namespace std;
const int MM = 2e4+5;
int n, b[MM], c[MM], dp[MM], k;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n; memset(dp, 0x3f, sizeof(dp)); dp[0]=0;
    for (int i=1; i<=n; i++) cin >> b[i];
    for (int i=1; i<=n; i++) cin >> c[i];
    cin >> k;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=c[i]; j<<=1) {
            int v = b[i]*j;
            for (int p=k; p>=v; p--) dp[p]=min(dp[p], dp[p-v]+j);
            c[i]-=j;
        }
        for (int p=k; p>=c[i]*b[i]; p--) dp[p]=min(dp[p], dp[p-c[i]*b[i]]+c[i]);
    }
    cout << dp[k] << '\n';
}