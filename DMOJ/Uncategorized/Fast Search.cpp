#include <bits/stdc++.h>
using namespace std;
const int MM = 1e6+5;
#define lc (rt<<1)
#define rc (rt<<1|1)
#define nl '\n'
#define inf 0x3F3F3F3F
struct node { int l, r, mn; } seg[4*MM];
int N, Q, ans;
void pushup(int rt) { seg[rt].mn = min(seg[lc].mn, seg[rc].mn); }
void build(int l, int r, int rt) {
    seg[rt].l = l; seg[rt].r = r;
    if (l == r) { cin >> seg[rt].mn; return; }
    int mid = (l+r)/2;
    build(l, mid, lc); build(mid+1, r, rc);
    pushup(rt);
}
void update(int p, int x, int rt) {
    if (seg[rt].l == seg[rt].r) { seg[rt].mn = x; return; }
    int mid = (seg[rt].l + seg[rt].r) / 2;
    if (p <= mid) update(p, x, lc);
    else update(p, x, rc);
    pushup(rt);
}
int query(int l, int r, int k, int rt) {
    if (seg[rt].mn >= k) return inf;
    if (seg[rt].l == l && seg[rt].r == r) {
        int lo = l, hi = r;
        while (lo < hi) {
            int mid = (lo+hi)/2;
            if (seg[lc].mn < k) { hi = mid; rt = lc; }
            else { lo = mid+1; rt = rc; }
        }
        return lo;
    }
    int mid = (seg[rt].l + seg[rt].r) / 2;
    if (r <= mid) return query(l, r, k, lc);
    else if (l > mid) return query(l, r, k, rc);
    int p = query(l, mid, k, lc);
    return p!=inf?p:query(mid+1, r, k, rc);
}
void solve(int tc) {
    cin >> N >> Q; build(1, N, 1);
    for (int i=1, op, p, x, l, r, k; i<=Q; i++) {
        cin >> op;
        if (op == 1) {
            cin >> p >> x; p^=ans; x^=ans;
            update(p, x, 1);
        } else {
            cin >> l >> r >> k; l^=ans; r^=ans; k^=ans;
            ans = query(l, r, k, 1);
            cout << ans << nl;
        }
    }
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int tc = 1; /*cin >> tc;*/ for (int t = 1; t <= tc; t++) solve(t); return 0; }