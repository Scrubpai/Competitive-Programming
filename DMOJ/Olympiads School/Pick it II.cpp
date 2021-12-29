#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e5+5;
int N, K, a[MM], q[MM], l, r; ll dp[MM], sum, ans;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N >> K;
    for (int i=1; i<=N; i++) {
        cin >> a[i]; sum += a[i];
        while (l < r && q[l] < i-K-1) l++;
        dp[i] = dp[q[l]] + a[i];
        while (l < r && dp[i] <= dp[q[r]]) r--;
        q[++r] = i;
    }
    for (int i=N-K; i<=N; i++) ans = max(ans, sum - dp[i]);
    printf("%lld\n", ans);
    return 0;
}