#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define nl '\n'

int n, dp[21][21];

ll factorial(ll x) {
    ll ret = 1;
    for (; x >= 1; x--) ret *= x;
    return ret;
}

void solve(int tc) {

    cin >> n; dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i) dp[i][j] = 1;
            else dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
        }
    }
    cout << (1LL * dp[n][n/2] / 2) * ((ll)pow(factorial(n / 2 - 1), 2)) << nl;


}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}