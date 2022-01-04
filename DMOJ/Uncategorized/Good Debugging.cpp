#include <bits/stdc++.h>
using namespace std;
const int MM = 1e6+5;
#define nl '\n'
struct node { int l, r, ok, bad, lz; } seg[3*MM];
int N, M, L;
void pushup(int rt) {
    int lc = 2*rt, rc = 2*rt+1;
    seg[rt].bad = seg[lc].bad + seg[rc].bad;
    seg[rt].ok = seg[lc].ok + seg[rc].ok;
}
void pushdown(int rt) {
    int lc = 2*rt, rc = 2*rt+1;
    seg[lc].lz ^= seg[rt].lz; seg[rc].lz ^= seg[rt].lz;
    swap(seg[lc].bad, seg[lc].ok); swap(seg[rc].bad, seg[rc].ok);
    seg[rt].lz = 0;
}
void build(int l, int r, int rt) {
    seg[rt].l = l; seg[rt].r = r; seg[rt].lz = 0;
    if (l == r) { seg[rt].bad = 1; seg[rt].ok = 0; return; }
    int mid = (l + r) / 2;
    build(l, mid, 2*rt); build(mid+1, r, 2*rt+1); pushup(rt);
}
void update(int l, int r, int rt) {
    if (seg[rt].l == l && seg[rt].r == r) {
        seg[rt].lz ^= 1;
        swap(seg[rt].ok, seg[rt].bad);
        return;
    }
    if (seg[rt].lz) pushdown(rt);
    int mid = (seg[rt].l + seg[rt].r) / 2;
    if (r <= mid) update(l, r, 2*rt);
    else if (l > mid) update(l, r, 2*rt+1);
    else update(l, mid, 2*rt), update(mid+1, r, 2*rt+1);
    pushup(rt);
}
int query(int v, int rt) {
    if (seg[rt].l == seg[rt].r) return seg[rt].l;
    if (seg[rt].lz) pushdown(rt);
    if (v <= seg[2*rt].bad) return query(v, 2*rt);
    else return query(v-seg[2*rt].bad, 2*rt+1);
}
void solve(int tc) {
    cin >> N >> M >> L;
    build(1, N, 1);
    for (int i=1, a, b; i<=M; i++) {
        cin >> a >> b;
        update(a, b, 1);
        if (seg[1].bad < L) cout << "AC?" << nl;
        else cout << query(L, 1) << nl;
    }
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); int tc = 1; /*cin >> tc;*/ for (int t = 1; t <= tc; t++) solve(t); return 0; }