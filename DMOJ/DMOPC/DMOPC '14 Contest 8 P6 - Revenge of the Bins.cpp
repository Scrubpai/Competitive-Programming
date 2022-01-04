#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+5;
#define nl '\n'
struct node { int l, r, sum, pre; } seg[3*MM];
int N, s[MM];
void pushup(int rt) {
    seg[rt].sum = seg[2*rt].sum + seg[2*rt+1].sum;
    seg[rt].pre = min(seg[2*rt].pre, seg[2*rt].sum + seg[2*rt+1].pre);
}
void build(int l, int r, int rt) {
    seg[rt].l = l; seg[rt].r = r; seg[rt].sum = 0; seg[rt].pre = 0;
    if (l == r) return;
    int mid = (l + r) / 2;
    build(l, mid, 2*rt); build(mid+1, r, 2*rt+1);
}
void update(int p, int v, int rt) {
    if (seg[rt].l == seg[rt].r) { seg[rt].sum = seg[rt].pre = v; return; }
    int mid = (seg[rt].l + seg[rt].r) / 2;
    if (p <= mid) update(p, v, 2*rt);
    else update(p, v, 2*rt+1);
    pushup(rt);
}
void solve(int tc) {
    cin >> N;
    for (int i=1; i<=N; i++) cin >> s[i];
    build(1, N, 1);
    int ans = 0;
    for (int i=1; i<=N/2; i++) {
        update(s[i], -1, 1);
        if (i>1) update(s[2*i-1], 1, 1);
        update(s[2*i], 1, 1);
        if (seg[1].pre >= 0) ans = i;
    }
    cout << ans << nl;
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int tc = 1; /*cin >> tc;*/ for (int t = 1; t <= tc; t++) solve(t); return 0; }