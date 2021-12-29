#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5;
int N, M, K, psa[MM+2], t[6], a[6]; double ans;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N >> M >> K;
    for (int i=1; i<=K; i++) cin >> t[i] >> a[i];
    for (int i=1, s, l, x; i<=M; i++) {
        cin >> s >> l >> x;
        psa[s+l+1] -= x; psa[s+1] += x;
    }
    for (int i=1; i<=MM+1; i++) {
        psa[i] += psa[i-1];
        double cur = psa[i];
        for (int j=1; j<=K; j++) {
            cur = min(cur, 1.0*(100-a[j])/100*(max(0, psa[i]-t[j])));
        }
        ans += cur;
    }
    if (N >= ans) printf("%.2f\n", N-ans);
    else printf("Act Like A Cactus.\n");
}