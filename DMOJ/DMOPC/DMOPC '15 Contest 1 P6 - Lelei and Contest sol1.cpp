#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define nl '\n'
const int MM = 2e5 + 5;
struct node {int l, r; ll sum, lz; } seg[3*MM];
int M, N, Q;
void pushup(int idx) { seg[idx].sum = (seg[2*idx].sum + seg[2*idx+1].sum) % M; }
void pushdown(int idx) {
    int lft = 2*idx, rit = 2*idx+1;
    seg[lft].lz += seg[idx].lz; seg[rit].lz += seg[idx].lz;
    seg[lft].sum = (seg[lft].sum + (ll)(seg[lft].r - seg[lft].l + 1)*seg[idx].lz) % M;
    seg[rit].sum = (seg[rit].sum + (ll)(seg[rit].r - seg[rit].l + 1)*seg[idx].lz) % M;
    seg[idx].lz = 0;
}
void build(int l, int r, int idx) {
    seg[idx].l = l; seg[idx].r = r; seg[idx].lz = 0;
    if (l == r) { cin >> seg[idx].sum; seg[idx].sum %= M; return; }
    int mid = (l + r) / 2;
    build(l, mid, 2*idx); build(mid+1, r, 2*idx+1); pushup(idx);
}
void update(int l, int r, int val, int idx) {
    if (seg[idx].l == l && seg[idx].r == r) { seg[idx].lz += val; seg[idx].sum = (seg[idx].sum + (ll)(r-l+1)*val)%M; return; }
    if (seg[idx].lz != 0) pushdown(idx);
    int mid = (seg[idx].l + seg[idx].r) / 2;
    if (r <= mid) update(l, r, val, 2*idx);
    else if (l > mid) update(l, r, val, 2*idx+1);
    else update(l, mid, val, 2*idx), update(mid+1, r, val, 2*idx+1);
    pushup(idx);
}
ll query(int l, int r, int idx) {
    if (seg[idx].l == l && seg[idx].r == r) return seg[idx].sum % M;
    if (seg[idx].lz != 0) pushdown(idx);
    int mid = (seg[idx].l + seg[idx].r) / 2;
    if (r <= mid) return query(l, r, 2*idx);
    else if (l > mid) return query(l, r, 2*idx+1);
    else return (query(l, mid, 2*idx) + query(mid+1, r, 2*idx+1)) % M;
}
void solve(int tc) {
    cin >> M >> N >> Q; build(1, N, 1);
    for (int i = 1,  op, l, r, x; i <= Q; i++) {
        cin >> op >> l >> r;
        if (op == 1) { cin >> x; update(l, r, x, 1); }
        else { cout << query(l, r, 1) % M << nl; }
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}