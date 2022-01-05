#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 2e5+5;
#define nl '\n'
int N, K, Q;
struct node {
    int l, r; ll mx, lz;
} seg[3*MM];
void pushup(int id) {
    int lc = 2*id, rc = 2*id+1;
    seg[id].mx = max(seg[lc].mx, seg[rc].mx);
}
void pushdown(int id) {
    int lc = 2*id, rc = 2*id+1;
    seg[lc].mx += seg[id].lz; seg[rc].mx += seg[id].lz;
    seg[lc].lz += seg[id].lz; seg[rc].lz += seg[id].lz;
    seg[id].lz = 0;
}
void build(int l, int r, int id) {
    seg[id].l = l; seg[id].r = r; seg[id].mx = seg[id].lz = 0;
    if (l == r) return;
    int mid = (l+r)/2;
    build(l, mid, 2*id); build(mid+1, r, 2*id+1);
}
void update(int l, int r, int v, int id) {
    if (seg[id].l == l && seg[id].r == r) {
        seg[id].mx += v; seg[id].lz += v;
        return;
    }
    if (seg[id].lz != 0) pushdown(id);
    int mid = (seg[id].l + seg[id].r) / 2;
    if (r <= mid) update(l, r, v, 2*id);
    else if (l > mid) update(l, r, v, 2*id+1);
    else update(l, mid, v, 2*id), update(mid+1, r, v, 2*id+1);
    pushup(id);
}
ll query(int l, int r, int id) {
    if (seg[id].l == l && seg[id].r == r) return seg[id].mx;
    if (seg[id].lz != 0) pushdown(id);
    int mid = (seg[id].l + seg[id].r) / 2;
    if (r <= mid) return query(l, r, 2*id);
    else if (l > mid) return query(l, r, 2*id+1);
    else return max(query(l, mid, 2*id), query(mid+1, r, 2*id+1));
}
void solve(int tc) {
    cin >> N >> K >> Q;
    build(1, N, 1);
    for (int i=1, t, p, v, l, r; i<=Q; i++) {
        cin >> t;
        if (t == 0) {
            cin >> p >> v; p++;
            if (K) update(max(p-K+1, 1), p, v, 1);
        } else {
            cin >> l >> r; l++; r++;
            l = min(l, N); r = min(r, N);
            if (K) cout << query(l, r, 1) << nl;
            else cout << 0 << nl;
        }
    }
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int tc = 1; /*cin >> tc;*/ for (int t = 1; t <= tc; t++) solve(t); return 0; }