#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define lc rt<<1
#define rc ((rt<<1)|1)
const int MM = 1e5+5;
typedef pair<int, int> pi;
struct node { int l, r, v, lz; } seg[6*MM];
int T, N; pi a[MM]; vector<int> lft[2*MM], rit[2*MM], p;
void pushdown(int rt) {
    seg[lc].lz += seg[rt].lz; seg[rc].lz += seg[rt].lz;
    seg[lc].v += seg[rt].lz; seg[rc].v += seg[rt].lz;
    seg[rt].lz = 0;
}
void build(int l, int r, int rt) {
    seg[rt].l = l; seg[rt].r = r; seg[rt].v = seg[rt].lz = 0;
    if (l == r) { lft[l].clear(); rit[l].clear(); return; }
    int mid = l+r>>1;
    build(l, mid, lc); build(mid+1, r, rc);
}
void upd(int l, int r, int v, int rt) {
    if (seg[rt].l == l && seg[rt].r == r) {
        seg[rt].v += v; seg[rt].lz += v; return;
    }
    if (seg[rt].lz) pushdown(rt);
    int mid = seg[rt].l+seg[rt].r>>1;
    if (r <= mid) upd(l, r, v, lc);
    else if (l > mid) upd(l, r, v, rc);
    else upd(l, mid, v, lc), upd(mid+1, r, v, rc);
    seg[rt].v = max(seg[lc].v, seg[rc].v);
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    scanf("%d", &T);
    for (int tt=1; tt<=T; tt++) {
        memset(seg, 0, sizeof(seg)); p.clear();
        scanf("%d", &N);
        for (int i=0; i<N; i++) {
            scanf("%d %d", &a[i].f, &a[i].s);
            p.push_back(a[i].f); p.push_back(a[i].s);
        }
        sort(p.begin(), p.end()); p.resize(unique(p.begin(), p.end()) - p.begin());
        build(0, p.size()-1, 1);
        for (int i=0; i<N; i++) {
            a[i].f = lower_bound(p.begin(), p.end(), a[i].f) - p.begin();
            a[i].s = lower_bound(p.begin(), p.end(), a[i].s) - p.begin();
            lft[a[i].f].push_back(i); rit[a[i].s].push_back(i);
            upd(a[i].f, a[i].s, 1, 1);
        }
        int ans = 0, cnt = 0;
        for (int t=0; t<p.size(); t++) {
            for (int i : lft[t]) {
                cnt++;
                upd(a[i].f, a[i].s, -1, 1);
            }
            ans = max(ans, cnt + seg[1].v);
            cnt -= rit[t].size();
        }
        printf("Case %d: %d\n", tt, ans);
    }
    return 0;
}