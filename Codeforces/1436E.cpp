#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
#define INF 0x3f3f3f3f

const int MM = 1e5 + 5;
struct node {
    int l, r, v;
} seg[3*MM];
int n, a[MM], pre[MM]; bool vis[MM];

void build(int l, int r, int idx) {
    seg[idx].l = l; seg[idx].r = r;
    if (l == r) { seg[idx].v = -INF; return; }
    int mid = (l + r) / 2;
    build(l, mid, 2*idx); build(mid+1, r, 2*idx+1);
    seg[idx].v = -INF;
}

void update(int idx, int p, int val) {
    if (seg[idx].l == seg[idx].r) { seg[idx].v = val; return; }
    int mid = (seg[idx].l + seg[idx].r) / 2;
    if (p <= mid) update(2*idx, p, val);
    else update(2*idx+1, p, val);
    seg[idx].v = min(seg[2*idx].v, seg[2*idx+1].v);
}

int query(int l, int r, int idx) {
    if (seg[idx].l == l && seg[idx].r == r) return seg[idx].v;
    int mid = (seg[idx].l + seg[idx].r) / 2;
    if (r <= mid) return query(l, r, 2*idx);
    else if (l > mid) return query(l, r, 2*idx+1);
    else return min(query(l, mid, 2*idx), query(mid+1, r, 2*idx+1));
}

void solve(int tc) {

    cin >> n;
    build(1, n, 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] != 1) {
            vis[1] = 1;
            int last = query(1, a[i]-1, 1);
            if (last > pre[a[i]]) vis[a[i]] = 1;
            pre[a[i]] = i;
        }
        update(1, a[i], i);
    }
    for (int i = 2; i <= n + 1; i++) {
        int last = query(1, i - 1, 1);
        if (last > pre[i]) vis[i] = 1;
    }
    for (int i = 1; i <= n + 2; i++) {
        if (!vis[i]) {
            cout << i << nl;
            return;
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