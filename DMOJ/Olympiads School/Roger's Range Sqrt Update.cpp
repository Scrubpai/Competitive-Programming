#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define nl '\n'

const int MM = 1e5 + 5;
struct node {
    int l, r, mx; ll v;
} seg[3*MM];
int n, m, a[MM];

void build(int l, int r, int idx) {
    seg[idx].l = l; seg[idx].r = r;
    if (l == r) { seg[idx].v = seg[idx].mx = a[l]; return; }
    int mid = (l + r) / 2;
    build(l, mid, 2*idx); build(mid+1, r, 2*idx+1);
    seg[idx].v = seg[2*idx].v + seg[2*idx+1].v;
    seg[idx].mx = max(seg[2*idx].mx, seg[2*idx+1].mx);
}

ll query(int l, int r, int idx) {
    if (seg[idx].l == l && seg[idx].r == r) return seg[idx].v;
    int mid = (seg[idx].l + seg[idx].r) / 2;
    if (r <= mid) return query(l, r, 2*idx);
    else if (l > mid) return query(l, r, 2*idx+1);
    else return query(l, mid, 2*idx) + query(mid+1, r, 2*idx+1);
}

void update(int l, int r, int idx) {
    if (seg[idx].mx <= 1) return;
    if (seg[idx].l == seg[idx].r) {
        seg[idx].v = seg[idx].mx = (int)sqrt(seg[idx].v);
        return;
    }
    int mid = (seg[idx].l + seg[idx].r) / 2;
    if (r <= mid) update(l, r, 2*idx);
    else if (l > mid) update(l, r, 2*idx+1);
    else update(l, mid, 2*idx), update(mid+1, r, 2*idx+1);
    seg[idx].v = seg[2*idx].v + seg[2*idx+1].v; seg[idx].mx = max(seg[2*idx].mx, seg[2*idx+1].mx);
}

void solve(int tc) {

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build(1, n, 1);
    cin >> m;
    for (int i = 1, x, l, r; i <= m; i++) {
        cin >> x >> l >> r;
        if (x == 1) {
            cout << query(l, r, 1) << nl;
        } else {
            update(l, r, 1);
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