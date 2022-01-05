#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
const long long MAXN = numeric_limits<long long>::max();
typedef long long ll;

int n, w, v, c; int dp[1001];

void solve() {

    cin >> n >> w;
    for (int i=1; i<=n; i++) {
        cin >> v >> c;
        for (int j=w; j>=c; j--) {
            dp[j] = max(dp[j], dp[j-c] + v);
        }
    }

    cout << dp[w];

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}