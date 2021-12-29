#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5+5;
#define nl '\n'
int N, dp[MM][14], a[MM]; string S, X;
int fun(int i, int k) {
    if (i==N-1) {
        if (X[i]=='A') {
            if ((3*k)%7 == 0 && (3*k+a[i])%7 == 0) return 0;
            else return 1;
        } else {
            if ((3*k)%7 != 0 && (3*k+a[i])%7 != 0) return 0;
            else return 1;
        }
    }
    if (dp[i][k] != -1) return dp[i][k];
    if (X[i+1]==X[i]) return dp[i][k] = max(fun(i+1, (3*k)%7), fun(i+1, (3*k+a[i])%7));
    else return dp[i][k] = max(!fun(i+1, (3*k)%7), !fun(i+1, (3*k+a[i])%7));
}
void solve(int tc) {
    cin >> N >> S >> X;
    for (int i=0; i<N; i++) a[i] = (S[i]-'0');
    memset(dp, -1, sizeof(dp));
    if (fun(0, 0)) cout << ((X[0]=='A') ? "Aoki" : "Takahashi") << nl;
    else cout << ((X[0]=='A') ? "Takahashi" : "Aoki") << nl;
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int tc = 1; /*cin >> tc;*/ for (int t = 1; t <= tc; t++) solve(t); return 0; }