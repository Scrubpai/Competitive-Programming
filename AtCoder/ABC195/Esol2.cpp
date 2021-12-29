#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5+5;
#define nl '\n'
int N; string S, X;
void solve(int tc) {
    cin >> N >> S >> X; S = " " + S; X = " " + X;
    vector<vector<int>> dp(N+1, vector<int>(7, false));
    dp[N][0] = 1;
    for (int i=N; i>=1; i--) {
        for (int j=0; j<7; j++) {
            if (X[i]=='T') dp[i-1][j] = dp[i][(10*j)%7] || dp[i][(10*j+(S[i]-'0'))%7];
            else dp[i-1][j] = dp[i][(10*j)%7] && dp[i][(10*j+(S[i]-'0'))%7];
        }
    }
    printf("%s\n", dp[0][0]?"Takahashi":"Aoki");
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int tc = 1; /*cin >> tc;*/ for (int t = 1; t <= tc; t++) solve(t); return 0; }