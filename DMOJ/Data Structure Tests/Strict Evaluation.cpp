#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e5+5;
#define nl '\n'
struct node { int l, r; ll lz1, lz2, ans; } seg[4*MM];
int N, Q;
void pushup(int rt) { seg[rt].ans = min(seg[2*rt].ans, seg[2*rt+1].ans); }
void pushdown(int rt) {
    int lc = 2*rt, rc = 2*rt+1;
    if (seg[rt].lz2 != 0) {
        seg[lc].lz2 = seg[rc].lz2 = seg[rt].lz2;
        seg[lc].lz1 = 0; seg[rc].lz1 = 0;
        seg[lc].ans = seg[rc].ans = seg[rt].lz2;
        seg[rt].lz2 = 0;
    }
    if (seg[rt].lz1 != 0) {
        seg[lc].lz1 += seg[rt].lz1; seg[rc].lz1 += seg[rt].lz1;
        seg[lc].ans += seg[rt].lz1; seg[rc].ans += seg[rt].lz1;
        seg[rt].lz1 = 0;
    }
}
void build(int l, int r, int rt) {
    seg[rt].l = l; seg[rt].r = r; seg[rt].lz1 = seg[rt].lz2 = 0;
    if (l == r) { cin >> seg[rt].ans; return; }
    int mid = (l + r) / 2;
    build(l, mid, 2*rt); build(mid+1, r, 2*rt+1);
    pushup(rt);
}
void update1(int l, int r, int v, int rt) {
    if (seg[rt].l == l && seg[rt].r == r) { seg[rt].ans += v; seg[rt].lz1 += v; return; }
    if (seg[rt].lz1 != 0 || seg[rt].lz2 != 0) pushdown(rt);
    int mid = (seg[rt].l + seg[rt].r) / 2;
    if (r <= mid) update1(l, r, v, 2*rt);
    else if (l > mid) update1(l, r, v, 2*rt+1);
    else update1(l, mid, v, 2*rt), update1(mid+1, r, v, 2*rt+1);
    pushup(rt);
}
void update2(int l, int r, int v, int rt) {
    if (seg[rt].l == l && seg[rt].r == r) { seg[rt].ans = seg[rt].lz2 = v; seg[rt].lz1 = 0; return; }
    if (seg[rt].lz1 != 0 || seg[rt].lz2 != 0) pushdown(rt);
    int mid = (seg[rt].l + seg[rt].r) / 2;
    if (r <= mid) update2(l, r, v, 2*rt);
    else if (l > mid) update2(l, r, v, 2*rt+1);
    else update2(l, mid, v, 2*rt), update2(mid+1, r, v, 2*rt+1);
    pushup(rt);
}
ll query(int l, int r, int rt) {
    if (seg[rt].l == l && seg[rt].r == r) return seg[rt].ans;
    if (seg[rt].lz1 != 0 || seg[rt].lz2 != 0) pushdown(rt);
    int mid = (seg[rt].l + seg[rt].r) / 2;
    if (r <= mid) return query(l, r, 2*rt);
    else if (l > mid) return query(l, r, 2*rt+1);
    else return min(query(l, mid, 2*rt), query(mid+1, r, 2*rt+1));
}
void solve(int tc) {
    cin >> N >> Q;
    build(1, N, 1);
    for (int i=1, op, l, r, v; i<=Q; i++) {
        cin >> op;
        if (op == 1) {
            cin >> l >> r >> v;
            update1(l, r, v, 1);
        } else if (op == 2) {
            cin >> l >> r >> v;
            update2(l, r, v, 1);
        } else {
            cin >> l >> r;
            cout << query(l, r, 1) << nl;
        }
    }
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int tc = 1; /*cin >> tc;*/ for (int t = 1; t <= tc; t++) solve(t); return 0; }