#include <bits/stdc++.h>
using namespace std;
const int MM = 3e5 + 5;
#define nl '\n'
int N, Q;
struct node { int l, r, v; } seg[5*MM];
void pushup(int idx) { seg[idx].v = seg[2*idx].v ^ seg[2*idx+1].v; }
void build(int l, int r, int idx) {
    seg[idx].l = l; seg[idx].r = r;
    if (l == r) { cin >> seg[idx].v; return; }
    int mid = (l + r) / 2;
    build(l, mid, 2*idx); build(mid+1, r, 2*idx+1); pushup(idx);
}
void update(int p, int y, int idx) {
    if (seg[idx].l == seg[idx].r) { seg[idx].v ^= y; return; }
    int mid = (seg[idx].l + seg[idx].r) / 2;
    if (p <= mid) update(p, y, 2*idx);
    else update(p, y, 2*idx+1);
    pushup(idx);
}
int query(int l, int r, int idx) {
    if (seg[idx].l == l && seg[idx].r == r) return seg[idx].v;
    int mid = (seg[idx].l + seg[idx].r) / 2;
    if (r <= mid) return query(l, r, 2*idx);
    else if (l > mid) return query(l, r, 2*idx+1);
    else return query(l, mid, 2*idx) ^ query(mid+1, r, 2*idx+1);
}
void solve(int tc) {
    cin >> N >> Q; build(1, N, 1);
    for (int i = 1, T, X, Y; i <= Q; i++) {
        cin >> T >> X >> Y;
        if (T == 1) update(X, Y, 1);
        else cout << query(X, Y, 1) << nl;
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}