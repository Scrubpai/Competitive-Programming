#include <bits/stdc++.h>
using namespace std;
#define lc (rt<<1)
#define rc ((rt<<1)|1)
const int MM = 1e6+5;
struct event { int p, l, r, v; };
struct node { int l, r, v, lz; } seg[3*MM];
void pushdown(int rt) {
    seg[lc].lz += seg[rt].lz; seg[rc].lz += seg[rt].lz;
    seg[lc].v += seg[rt].lz; seg[rc].v += seg[rt].lz;
    seg[rt].lz = 0;
}
void pushup(int rt) { seg[rt].v = min(seg[lc].v, seg[rc].v); }
void build(int l, int r, int rt) {
    seg[rt].l = l; seg[rt].r = r; seg[rt].v = seg[rt].lz = 0;
    if (l == r) return;
    int mid = l+r>>1;
    build(l, mid, lc); build(mid+1, r, rc);
}
void update(int l, int r, int v, int rt) {
    if (seg[rt].l == l && seg[rt].r == r) {
        seg[rt].lz += v; seg[rt].v += v; return;
    }
    if (seg[rt].lz) pushdown(rt);
    int mid = seg[rt].l+seg[rt].r>>1;
    if (r <= mid) update(l, r, v, lc);
    else if (l > mid) update(l, r, v, rc);
    else update(l, mid, v, lc), update(mid+1, r, v, rc);
    pushup(rt);
}
int query(int l, int r, int rt) {
    if (seg[rt].l == l && seg[rt].r == r) return seg[rt].v;
    if (seg[rt].lz) pushdown(rt);
    int mid = seg[rt].l+seg[rt].r>>1;
    if (r <= mid) return query(l, r, lc);
    else if (l > mid) return query(l, r, rc);
    else return min(query(l, mid, lc), query(mid+1, r, rc));
}
int fac(int x) { if (x==0) return 1e9; int cnt=0; while(x>0&&x%2==0) x/=2, cnt++; return cnt; }
int N, M, K, cnt; map<int, int> mp;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N >> M >> K; vector<event> line1, line2;
    for (int i=1, t, l, b, r; i<=K; i++) {
        cin >> t >> l >> b >> r; t--; l--; b--; r--; mp[t]=0; mp[l]=0; mp[b+1]=0; mp[r+1]=0;
        line1.push_back({l, t, b+1, 1}); line1.push_back({r+1, t, b+1, -1});
        line2.push_back({t, l, r+1, 1}); line2.push_back({b+1, l, r+1, -1});
    }
    for (auto &x: mp) x.second = cnt++;
    sort(line1.begin(), line1.end(), [](event a, event b) { if (a.p!=b.p) return a.p<b.p; else return a.v>b.v; });
    sort(line2.begin(), line2.end(), [](event a, event b) { if (a.p!=b.p) return a.p<b.p; else return a.v>b.v; });
    int ans = min(fac(N), fac(M));
    build(0, cnt, 1);
    for (event e : line1) {
        int p = mp[e.p], l = mp[e.l], r = mp[e.r], v = e.v;
        int rmq1 = query(l, r, 1);
        update(l, r, v, 1);
        int rmq2 = query(l, r, 1);
        if ((rmq1==0 && rmq2==1) || (rmq1==1 && rmq2==0)) ans = min(ans, fac(e.p));
    }
    build(0, cnt, 1);
    for (event e : line2) {
        int p = mp[e.p], l = mp[e.l], r = mp[e.r], v = e.v;
        int rmq1 = query(l, r, 1);
        update(l, r, v, 1);
        int rmq2 = query(l, r, 1);
        if ((rmq1==0 && rmq2==1) || (rmq1==1 && rmq2==0)) ans = min(ans, fac(e.p));
    }
    cout << ans << '\n';
}