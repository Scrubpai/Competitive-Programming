#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
#define lc (rt<<1)
#define rc ((rt<<1)|1)
const int MM = 2e5+5;
struct node { int l, r; ll lz, v; } seg[3*MM];
int N, M; ll dp[MM]; vector<pi> rit[MM];
void pushdown(int rt) {
    seg[lc].lz += seg[rt].lz; seg[rc].lz += seg[rt].lz;
    seg[lc].v += seg[rt].lz; seg[rc].v += seg[rt].lz;
    seg[rt].lz = 0;
}
void pushup(int rt) { seg[rt].v = max(seg[lc].v, seg[rc].v); }
void build(int l, int r, int rt) {
    seg[rt].l = l; seg[rt].r = r; seg[rt].lz = 0;
    if (l == r) return;
    int mid = l+r>>1;
    build(l, mid, lc); build(mid+1, r, rc);
}
void update(int l, int r, ll v, int rt) {
    if (seg[rt].l == l && seg[rt].r == r) {
        seg[rt].lz += v; seg[rt].v += v;
        return;
    }
    if (seg[rt].lz) pushdown(rt);
    int mid = seg[rt].l+seg[rt].r>>1;
    if (r <= mid) update(l, r, v, lc);
    else if (l > mid) update(l, r, v, rc);
    else update(l, mid, v, lc), update(mid+1, r, v, rc);
    pushup(rt);
}
ll query(int l, int r, int rt) {
    if (seg[rt].l == l && seg[rt].r == r) return seg[rt].v;
    if (seg[rt].lz) pushdown(rt);
    int mid = seg[rt].l+seg[rt].r>>1;
    if (r <= mid) return query(l, r, lc);
    else if (l > mid) return query(l, r, rc);
    else return max(query(l, mid, lc), query(mid+1, r, rc));
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N >> M;
    for (int i=1, l, r, a; i<=M; i++) {
        cin >> l >> r >> a;
        rit[r].push_back({l, a});
    }
    build(1, N, 1);
    for (int i=1; i<=N; i++) {
        if (i>1) dp[i] = max(0ll, query(1, i-1, 1));
        update(i, i, dp[i], 1);
        for (pi p : rit[i]) {
            int l = p.first, v = p.second;
            update(l, i, v, 1);
        }
    }
    printf("%lld\n", max(0ll, query(1, N, 1)));
}