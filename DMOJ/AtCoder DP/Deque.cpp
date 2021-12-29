#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N, a[3005]; ll dp[3005][3005];
ll fun(int l, int r) {
    if (l > r) return 0;
    if (l == r) return a[l];
    if (dp[l][r] != -1) return dp[l][r];
    return dp[l][r] = max(a[l] - fun(l+1, r), a[r] - fun(l, r-1));
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N; memset(dp, -1, sizeof(dp));
    for (int i=1; i<=N; i++) cin >> a[i];
    printf("%lld\n", fun(1, N));
}