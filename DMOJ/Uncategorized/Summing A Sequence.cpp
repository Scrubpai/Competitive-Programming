#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e6+5;
int N; ll dp[MM], a[MM];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N;
    for (int i=1; i<=N; i++) {
        cin >> a[i];
        dp[i] = max({0ll, dp[i-1], dp[i-2] + a[i]});
    }
    printf("%lld\n", dp[N]);
    return 0;
}