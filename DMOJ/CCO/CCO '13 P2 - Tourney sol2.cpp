#include <bits/stdc++.h>
using namespace std;
const int MM = 1<<21;
#define nl '\n'
struct node { int l, r, v, ans; } seg[MM];
int N, M; char ch;
void pushup(int rt) {
    int lc = 2*rt, rc = 2*rt+1;
    if (seg[lc].v > seg[rc].v) seg[rt].v = seg[lc].v, seg[rt].ans = seg[lc].ans;
    else seg[rt].v = seg[rc].v, seg[rt].ans = seg[rc].ans;
}
void build(int l, int r, int rt) {
    seg[rt].l = l; seg[rt].r = r;
    if (l == r) { cin >> seg[rt].v; seg[rt].ans = l; return; }
    int mid = (l + r) / 2;
    build(l, mid, 2*rt); build(mid+1, r, 2*rt+1);
    pushup(rt);
}
void update(int p, int s, int rt) {
    if (seg[rt].l == seg[rt].r) { seg[rt].v = s; return; }
    int mid = (seg[rt].l + seg[rt].r) / 2;
    if (p <= mid) update(p, s, 2*rt);
    else update(p, s, 2*rt+1);
    pushup(rt);
}
int query(int p, int rt) {
    if (seg[rt].l == seg[rt].r) return 0;
    int mid = (seg[rt].l + seg[rt].r) / 2, add = seg[rt].ans == p ? 1 : 0;
    if (p <= mid) return query(p, 2*rt) + add;
    else return query(p, 2*rt+1) + add;
}
void solve(int tc) {
    cin >> N >> M;
    build(1, (1<<N), 1);
    for (int i=1, idx, s; i<=M; i++) {
        cin >> ch;
        if (ch == 'R') {
            cin >> idx >> s;
            update(idx, s, 1);
        } else if (ch == 'W') {
            cout << seg[1].ans << nl;
        } else {
            cin >> idx;
            cout << query(idx, 1) << nl;
        }
    }
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); int tc = 1; /*cin >> tc;*/ for (int t = 1; t <= tc; t++) solve(t); return 0; }