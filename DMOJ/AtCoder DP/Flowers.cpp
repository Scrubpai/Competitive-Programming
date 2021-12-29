#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 2e5+5;
int N, h[MM], a[MM]; ll dp[MM], bit[MM], ans;
void update(int p, ll v) { for (; p<=N; p+=p&-p) bit[p] = max(bit[p], v); }
ll query(int p) { ll ret = 0; for (; p>=1; p-=p&-p) ret = max(ret, bit[p]); return ret; }
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N;
    for (int i=1; i<=N; i++) cin >> h[i];
    for (int i=1; i<=N; i++) {
        cin >> a[i];
        dp[i] = query(h[i]) + a[i];
        ans = max(ans, dp[i]);
        update(h[i], dp[i]);
    }
    printf("%lld\n", ans);
}