#include <bits/stdc++.h>
using namespace std;
const int MM = 250005;
#define nl '\n'
int N, M, tmp[10]; string s;
struct node {
    int l, r, lz, a[10];
    node() { memset(a, 0, sizeof(a)); }
} seg[3*MM];
void pushup(int idx) {
    for (int i = 0; i < 10; i++) {
        seg[idx].a[i] = seg[2*idx].a[i] + seg[2*idx+1].a[i];
    }
}
void pushdown(int idx) {
    int lft = 2*idx, rit = 2*idx+1;
    seg[lft].lz += seg[idx].lz; seg[rit].lz += seg[idx].lz; seg[lft].lz %= 10; seg[rit].lz %= 10;
    for (int i = 0; i < 10; i++) tmp[i] = seg[lft].a[i];
    for (int i = 0; i < 10; i++) seg[lft].a[i] = tmp[(i-seg[idx].lz+10)%10];
    for (int i = 0; i < 10; i++) tmp[i] = seg[rit].a[i];
    for (int i = 0; i < 10; i++) seg[rit].a[i] = tmp[(i-seg[idx].lz+10)%10];
    seg[idx].lz = 0;
}
void build(int l, int r, int idx) {
    seg[idx].l = l; seg[idx].r = r; seg[idx].lz = 0;
    if (l == r) { seg[idx].a[s[l-1]-'0'] = 1; return; }
    int mid = (l + r) / 2;
    build(l, mid, 2*idx); build(mid+1, r, 2*idx+1); pushup(idx);
}
void update(int l, int r, int idx) {
    if (seg[idx].l == l && seg[idx].r == r) {
        seg[idx].lz++; seg[idx].lz %= 10;
        for (int i = 0; i < 10; i++) tmp[i] = seg[idx].a[i];
        for (int i = 0; i < 10; i++) seg[idx].a[i] = tmp[(i-1+10)%10];
        return;
    }
    if (seg[idx].lz != 0) pushdown(idx);
    int mid = (seg[idx].l + seg[idx].r) / 2;
    if (r <= mid) update(l, r, 2*idx);
    else if (l > mid) update(l, r, 2*idx+1);
    else update(l, mid, 2*idx), update(mid+1, r, 2*idx+1);
    pushup(idx);
}
node query(int l, int r, int idx) {
    if (seg[idx].l == l && seg[idx].r == r) return seg[idx];
    if (seg[idx].lz != 0) pushdown(idx);
    int mid = (seg[idx].l + seg[idx].r) / 2;
    if (r <= mid) return query(l, r, 2*idx);
    else if (l > mid) return query(l, r, 2*idx+1);
    else {
        node lft = query(l, mid, 2*idx), rit = query(mid+1, r, 2*idx+1), ret;
        for (int i = 0; i < 10; i++) {
            ret.a[i] = lft.a[i] + rit.a[i];
        }
        return ret;
    }
}
void solve(int tc) {
    cin >> N >> M >> s; build(1, N, 1);
    for (int i = 1, A, B; i <= M; i++) {
        cin >> A >> B;
        int sum = 0;
        node ans = query(A, B, 1);
        for (int j = 0; j < 10; j++) sum += j*ans.a[j];
        cout << sum << nl;
        update(A, B, 1);
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}