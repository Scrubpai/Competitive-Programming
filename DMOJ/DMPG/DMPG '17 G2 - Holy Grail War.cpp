#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e5+5;
#define nl '\n'
struct node { int l, r; ll sum, pre, suf, mx; } seg[3*MM];
void pushup(int rt) {
    int lc = 2*rt, rc = 2*rt+1;
    seg[rt].sum = seg[lc].sum + seg[rc].sum;
    seg[rt].pre = max(seg[lc].pre, seg[lc].sum + seg[rc].pre);
    seg[rt].suf = max(seg[rc].suf, seg[rc].sum + seg[lc].suf);
    seg[rt].mx = max({seg[lc].mx, seg[rc].mx, seg[lc].suf + seg[rc].pre});
}
void build(int l, int r, int rt) {
    seg[rt].l = l; seg[rt].r = r;
    if (l == r) { cin >> seg[rt].mx; seg[rt].sum = seg[rt].pre = seg[rt].suf = seg[rt].mx; return; }
    int mid = (l + r) / 2;
    build(l, mid, 2*rt); build(mid+1, r, 2*rt+1); pushup(rt);
}
void update(int p, ll v, int rt) {
    if (seg[rt].l == seg[rt].r) { seg[rt].sum = seg[rt].pre = seg[rt].suf = seg[rt].mx = v; return; }
    int mid = (seg[rt].l + seg[rt].r) / 2;
    if (p <= mid) update(p, v, 2*rt);
    else update(p, v, 2*rt+1);
    pushup(rt);
}
node query(int l, int r, int rt) {
    if (seg[rt].l == l && seg[rt].r == r) return seg[rt];
    int mid = (seg[rt].l + seg[rt].r) / 2;
    if (r <= mid) return query(l, r, 2*rt);
    else if (l > mid) return query(l, r, 2*rt+1);
    else {
        node ret;
        node lft = query(l, mid, 2*rt), rit = query(mid+1, r, 2*rt+1);
        ret.sum = lft.sum + rit.sum;
        ret.pre = max(lft.pre, lft.sum + rit.pre);
        ret.suf = max(rit.suf, rit.sum + lft.suf);
        ret.mx = max({lft.mx, rit.mx, lft.suf + rit.pre});
        return ret;
    }
}
int N, Q; char ch;
void solve(int tc) {
    cin >> N >> Q;
    build(1, N, 1);
    for (int i=1, l, r, idx, x; i<=Q; i++) {
        cin >> ch;
        if (ch == 'S') {
            cin >> idx >> x;
            update(idx, x, 1);
        } else {
            cin >> l >> r;
            cout << query(l, r, 1).mx << nl;
        }
    }
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); int tc = 1; /*cin >> tc;*/ for (int t = 1; t <= tc; t++) solve(t); return 0; }