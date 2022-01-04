#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
#define INF 0x3f3f3f3f
const int MM = 2e5 + 5;
int N, Q; char op;
struct node {
    int l, r, stop;
} seg[3*MM];
void pushup(int idx) {
    seg[idx].stop = min(seg[2*idx].stop, seg[2*idx+1].stop);
}
void build(int l, int r, int idx) {
    seg[idx].l = l; seg[idx].r = r; seg[idx].stop = INF;
    if (l == r) return;
    int mid = (l + r) / 2;
    build(l, mid, 2*idx); build(mid+1, r, 2*idx+1);
}
void update(int p, int val, int idx) {
    if (seg[idx].l == seg[idx].r) { seg[idx].stop = val; return; }
    int mid = (seg[idx].l + seg[idx].r) / 2;
    if (p <= mid) update(p, val, 2*idx);
    else update(p, val, 2*idx+1);
    pushup(idx);
}
int query(int l, int r, int idx, int val) {
    if (seg[idx].stop > val) return INF;
    if (seg[idx].l == seg[idx].r) return seg[idx].l;
    int mid = (seg[idx].l + seg[idx].r) / 2;
    if (l > mid) return query(l, r, 2*idx+1, val);
    int t = query(l, mid, 2*idx, val);
    if (t != INF) return t;
    return query(mid+1, r, 2*idx+1, val);
}
void solve(int tc) {
    cin >> N >> Q;
    build(1, N, 1);
    for (int i = 1, X, A, Y, B; i <= Q; i++) {
        cin >> op;
        if (op == 'M') {
            cin >> X >> A;
            update(A, X, 1);
        } else {
            cin >> Y >> B;
            int ans = query(B, N, 1, Y);
            if (ans == INF) cout << -1 << nl;
            else cout << ans << nl;
        }
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}