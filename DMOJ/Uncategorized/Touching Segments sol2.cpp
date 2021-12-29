#include <bits/stdc++.h>
#define f first
#define s second
#define lc (rt<<1)
#define rc ((rt<<1)|1)
using namespace std;
const int MM = 1e5+5;
struct event { int p, v, idx; };
struct node { int l, r, v, lz; } seg[6*MM];
int T, N, cnt, a[MM], b[MM]; vector<int> p; vector<event> line;
void pushdown(int rt) {
    seg[lc].lz += seg[rt].lz; seg[rc].lz += seg[rt].lz;
    seg[lc].v += seg[rt].lz; seg[rc].v += seg[rt].lz;
    seg[rt].lz = 0;
}
void build(int l, int r, int rt) {
    seg[rt].l = l; seg[rt].r = r; seg[rt].lz = seg[rt].v = 0;
    if (l == r) return;
    int mid = (seg[rt].l + seg[rt].r) / 2;
    build(l, mid, lc); build(mid+1, r, rc);
}
void update(int l, int r, int v, int rt) {
    if (seg[rt].l == l && seg[rt].r == r) { seg[rt].lz += v; seg[rt].v += v; return; }
    if (seg[rt].lz) pushdown(rt);
    int mid = (seg[rt].l + seg[rt].r) / 2;
    if (r <= mid) update(l, r, v, lc);
    else if (l > mid) update(l, r, v, rc);
    else update(l, mid, v, lc), update(mid+1, r, v, rc);
    seg[rt].v = max(seg[lc].v, seg[rc].v);
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    scanf("%d", &T);
    for (int tt=1; tt<=T; tt++) {
        scanf("%d", &N); line.clear(); p.clear(); cnt = 0;
        for (int i=1; i<=N; i++) {
            scanf("%d %d", &a[i], &b[i]);
            p.push_back(a[i]); p.push_back(b[i]);
        }
        sort(p.begin(), p.end()); p.resize(unique(p.begin(), p.end()) - p.begin());
        build(0, p.size(), 1);
        for (int i=1; i<=N; i++) {
            a[i] = lower_bound(p.begin(), p.end(), a[i]) - p.begin();
            b[i] = lower_bound(p.begin(), p.end(), b[i]) - p.begin();
            line.push_back({a[i], 1, i}); line.push_back({b[i], -1, i});
            update(a[i], b[i], 1, 1);
        }
        sort(line.begin(), line.end(), [](event a, event b) { if (a.p!=b.p) return a.p<b.p; else return a.v>b.v; });
        int ans = 0, cur = 0;
        for (event e : line) {
            if (e.v == 1) { //left
                cur++;
                update(a[e.idx], b[e.idx], -1, 1);
            } else { //right
                cur--;
            }
            ans = max(ans, cur + seg[1].v);
        }
        printf("Case %d: %d\n", tt, ans);
    }
    return 0;
}