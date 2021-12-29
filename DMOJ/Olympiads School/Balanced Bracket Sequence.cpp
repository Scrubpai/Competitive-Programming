#include <bits/stdc++.h>
using namespace std;
string s; int dp[305][305];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> s; int n = (int)s.size(); s = " " + s;
    for (int i=1; i<=n; i++) dp[i][i] = 1;
    for (int len=2; len<=n; len++) {
        for (int l=1; l+len-1<=n; l++) {
            int r = l+len-1; dp[l][r] = 1e9;
            if ((s[l]=='('&&s[r]==')') || (s[l]=='['&&s[r]==']') || (s[l]=='{'&&s[r]=='}')) dp[l][r] = dp[l+1][r-1];
            for (int k=l; k<r; k++) {
                dp[l][r] = min(dp[l][r], dp[l][k] + dp[k+1][r]);
            }
        }
    }
    printf("%d\n", dp[1][n]);
}