#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
const int MM = 1.5e5+5;
struct node { int l, r, g, lz; } seg[4*MM];
int N, M, x[MM], y[MM], z[MM];
void pushup(int rt) { seg[rt].g = __gcd(seg[2*rt].g, seg[2*rt+1].g); }
void pushdown(int rt) {
    int lc = 2*rt, rc = 2*rt+1;
    seg[lc].lz = seg[lc].lz * seg[rt].lz / __gcd(seg[lc].lz, seg[rt].lz);
    seg[rc].lz = seg[rc].lz * seg[rt].lz / __gcd(seg[rc].lz, seg[rt].lz);
    seg[lc].g = seg[lc].g * seg[rt].lz / __gcd(seg[lc].g, seg[rt].lz);
    seg[rc].g = seg[rc].g * seg[rt].lz / __gcd(seg[rc].g, seg[rt].lz);
    seg[rt].lz = 1;
}
void build(int l, int r, int rt) {
    seg[rt].l = l; seg[rt].r = r; seg[rt].g = seg[rt].lz = 1;
    if (l == r) return;
    int mid = (l + r) / 2;
    build(l, mid, 2*rt); build(mid+1, r, 2*rt+1);
}
void update(int l, int r, int v, int rt) {
    if (seg[rt].l == l && seg[rt].r == r) {
        seg[rt].lz = seg[rt].lz * v / __gcd(seg[rt].lz, v);
        seg[rt].g = seg[rt].g * v / __gcd(seg[rt].g, v);
        return;
    }
    if (seg[rt].lz != 1) pushdown(rt);
    int mid = (seg[rt].l + seg[rt].r) / 2;
    if (r <= mid) update(l, r, v, 2*rt);
    else if (l > mid) update(l, r, v, 2*rt+1);
    else update(l, mid, v, 2*rt), update(mid+1, r, v, 2*rt+1);
    pushup(rt);
}
int query(int l, int r, int rt) {
    if (seg[rt].l == l && seg[rt].r == r) return seg[rt].g;
    if (seg[rt].lz != 1) pushdown(rt);
    int mid = (seg[rt].l + seg[rt].r) / 2;
    if (r <= mid) return query(l, r, 2*rt);
    else if (l > mid) return query(l, r, 2*rt+1);
    else return __gcd(query(l, mid, 2*rt), query(mid+1, r, 2*rt+1));
}
void solve(int tc) {
    cin >> N >> M;
    build(1, N, 1);
    for (int i=1; i<=M; i++) {
        cin >> x[i] >> y[i] >> z[i];
        update(x[i], y[i], z[i], 1);
    }
    for (int i=1; i<=M; i++) {
        if (query(x[i], y[i], 1) != z[i]) {
            cout << "Impossible" << nl;
            return;
        }
    }
    for (int i=1; i<=N; i++) cout << query(i, i, 1) << ' ';
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); int tc = 1; /*cin >> tc;*/ for (int t = 1; t <= tc; t++) solve(t); return 0; }