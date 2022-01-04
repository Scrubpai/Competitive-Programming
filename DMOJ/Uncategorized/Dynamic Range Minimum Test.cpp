#include <bits/stdc++.h>
using namespace std;
#define nl '\n'

const int MM = 1e5 + 5;
struct node {
    int l, r, v;
} seg[3*MM];
int n, m, p, x, a[MM]; char ch;

void build(int l, int r, int idx) {
    seg[idx].l = l; seg[idx].r = r;
    if (l == r) { seg[idx].v = a[l]; return; }
    int mid = (l + r) / 2;
    build(l, mid, 2*idx); build(mid+1, r, 2*idx+1);
    seg[idx].v = min(seg[2*idx].v, seg[2*idx+1].v);
}

void update(int idx, int pos, int val) {
    int l = seg[idx].l, r = seg[idx].r;
    if (l == r) {
        seg[idx].v = val;
        return;
    }
    int mid = (l + r) / 2;
    if (pos <= mid) update(idx*2, pos, val);
    else update(idx*2+1, pos, val);
    seg[idx].v = min(seg[idx*2].v, seg[idx*2+1].v);
}

int query(int l, int r, int idx) {
    if (seg[idx].l == l && seg[idx].r == r) return seg[idx].v;
    int mid = (seg[idx].l + seg[idx].r) / 2;
    if (r <= mid) return query(l, r, 2*idx);
    else if (l > mid) return query(l, r, 2*idx+1);
    else return min(query(l, mid, 2*idx), query(mid+1, r, 2*idx+1));
}

void solve(int tc) {

    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build(1, n, 1);
    while (m--) {
        cin >> ch >> p >> x;
        p++;
        if (ch == 'M') {
            update(1, p, x);
        } else {
            x++;
            cout << query(p, x, 1) << nl;
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