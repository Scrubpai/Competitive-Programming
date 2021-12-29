#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N; ll a[1005], dp[1005];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N;
    for (int i=1; i<=N; i++) {
        cin >> a[i];
        for (int j=i; j; j--) {
            dp[i] = max(dp[i], dp[i-j] + a[j]);
        }
    }
    printf("%lld\n", dp[N]);
    return 0;
}