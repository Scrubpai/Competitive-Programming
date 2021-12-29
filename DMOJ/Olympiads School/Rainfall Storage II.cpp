#include <bits/stdc++.h>
using namespace std;
const int MM = 1e6+5;
int n, h[MM], pre[MM], suf[MM];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> h[i];
        pre[i] = max(pre[i-1], h[i]);
    }
    long long ans = 0;
    for (int i=n; i>=1; i--) {
        suf[i] = max(suf[i+1], h[i]);
        ans += min(pre[i], suf[i]) - h[i];
    }
    printf("%lld\n", ans);
}