#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define nl '\n'
#define fi first
#define se second
const int MM = 5e5 + 5;
struct seg { int l, r, i; } queries[MM];
bool cmp(seg a, seg b) { return a.r < b.r; }
int N, Q, bit[MM], c[MM], idx[MM], ans[MM];
void update(int p, int v) { for (; p <= N; p += p&-p) bit[p] += v; }
int query(int p) { int ret = 0; for (; p >= 1; p -= p&-p) ret += bit[p]; return ret; }
void solve(int tc) {
    cin >> N >> Q;
    for (int i = 1; i <= N; i++) cin >> c[i];
    for (int i = 1, l, r; i <= Q; i++) {
        cin >> l >> r;
        queries[i] = {l, r, i};
    }
    sort(queries + 1, queries + 1 + Q, cmp);
    memset(idx, -1, sizeof(idx));
    int p = 0;
    for (int i = 1; i <= Q; i++) {
        while (p < queries[i].r) {
            int pre = idx[c[++p]];
            if (pre != -1) update(pre, -1);
            idx[c[p]] = p;
            update(p, 1);
        }
        ans[queries[i].i] = query(queries[i].r) - query(queries[i].l-1);
    }
    for (int i = 1; i <= Q; i++) cout << ans[i] << nl;
}
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}