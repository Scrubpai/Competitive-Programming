#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
typedef pair<int, int> pii;
const int MM = 1e4, MN = 1e5+5;
struct query { int c, l, id; };
int N, V, d[2005], dp[MM+1], ans[MN]; query q[MN];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    memset(dp, 0x3f, sizeof(dp)); dp[0] = 0;
    cin >> N >> V;
    for (int i=1; i<=N; i++) cin >> d[i];
    for (int i=1; i<=V; i++) { cin >> q[i].c >> q[i].l; q[i].id = i; }
    sort(q+1, q+1+V, [](query a, query b) { return a.l < b.l; });
    for (int i=1, id=0; i<=V; i++) {
        while (id<q[i].l) {
            id++;
            for (int j=d[id]; j<=MM; j++) {
                dp[j] = min(dp[j], dp[j-d[id]] + 1);
            }
        }
        ans[q[i].id] = dp[q[i].c];
    }
    for (int i=1; i<=V; i++) printf("%d\n", ans[i]>1e9?-1:ans[i]);
}