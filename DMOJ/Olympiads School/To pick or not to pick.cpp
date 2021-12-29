#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e5;
int n, a[MM+1], cnt[MM+1]; ll dp[MM+1];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    dp[1] = cnt[1];
    for (int i=2; i<=MM; i++) {
        dp[i] = max(dp[i-1], dp[i-2] + 1ll*i*cnt[i]);
    }
    printf("%lld\n", dp[MM]);
}