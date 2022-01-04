#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define nl '\n'
int N, K; ll dp[255][255];
ll fun(int n, int k) {
    if (n == k || (n > 0 && k == 1)) return 1;
    if (n < k || n < 0 || k < 0) return 0;
    if (dp[n][k] != -1) return dp[n][k];
    return dp[n][k] = fun(n - 1, k - 1) + fun(n - k, k);
}
void solve(int tc) {
    cin >> N >> K;
    memset(dp, -1, sizeof(dp));
    cout << fun(N, K) << nl;
}
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}