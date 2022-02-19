#include <bits/stdc++.h>
using namespace std;
const int MM = 1e6+5, MQ = 5e4+5;
struct query {
    int l, r, x, id;
    bool operator < (const query&other) const {
        return this->r < other.r;
    }
} q[MQ];
int N, Q, a[MM], vis[MM], ans[MQ];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N >> Q;
    for (int i=1; i<=N; i++) cin >> a[i];
    for (int i=1; i<=Q; i++) { cin >> q[i].l >> q[i].r >> q[i].x; q[i].id = i; }
    sort(q+1, q+1+Q);
    for (int i=1, j=1; i<=Q; i++) {
        while (j <= q[i].r) vis[a[j]] = j, j++;
        for (int k=1; k*k<q[i].x; k++) {
            if (q[i].x%k==0) {
                if (vis[k] >= q[i].l && vis[q[i].x/k] >= q[i].l) {
                    ans[q[i].id] = 1;
                    break;
                }
            }
        }
    }
    for (int i=1; i<=Q; i++) cout << (ans[i]?"YES\n":"NO\n");
}