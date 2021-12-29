#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+5;
typedef long long ll;
int N, M, a[MM];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N >> M;
    for (int i=0; i<N; i++) cin >> a[i];
    sort(a, a+N);
    ll ans = 0;
    for (int i=1; i<N; i++) {
        int idx = upper_bound(a, a+i, M-a[i]) - a;
        ans += idx;
    }
    printf("%lld\n", ans);
}