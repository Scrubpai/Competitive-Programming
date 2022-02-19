#include <bits/stdc++.h>
using namespace std;
const int MM = 1e4+1;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    vector<int> ntb(1001, 1e9); ntb[1] = 0;
    for (int i=1; i<=1000; i++) {
        for (int j=1; j<=i; j++) {
            if (i+i/j > 1000) continue;
            ntb[i+i/j] = min(ntb[i+i/j], ntb[i] + 1);
        }
    }
    int t; cin >> t;
    for (int tt=0, n, k; tt<t; tt++) {
        cin >> n >> k;
        vector<int> b(n+1), c(n+1);
        int tot = 0;
        for (int i=1; i<=n; i++) { cin >> b[i]; tot += ntb[b[i]]; }
        for (int i=1; i<=n; i++) cin >> c[i];
        vector<int> dp(tot+1);
        for (int i=1; i<=n; i++) {
            for (int j=min(k, tot); j>=ntb[b[i]]; j--) {
                dp[j] = max(dp[j], dp[j-ntb[b[i]]] + c[i]);
            }
        }
        cout << dp[min(k, tot)] << '\n';
    }
}