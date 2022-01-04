#include <bits/stdc++.h>
using namespace std;
#define nl '\n'

const int MM = 1e5 + 5;
int gcd(int a, int b){return b == 0 ? a : gcd(b, a % b);}
struct node {
    int l, r, v, g, cnt;
} seg[3*MM];
int n, m, a[MM]; char op;

void pushup(int idx) {
    int lft = 2*idx, rit = 2*idx+1;
    seg[idx].v = min(seg[lft].v, seg[rit].v);
    seg[idx].g = gcd(seg[lft].g, seg[rit].g);
    seg[idx].cnt = 0;
    if (seg[idx].g == seg[lft].g) seg[idx].cnt += seg[lft].cnt;
    if (seg[idx].g == seg[rit].g) seg[idx].cnt += seg[rit].cnt;
}

void build(int l, int r, int idx) {
    seg[idx].l = l; seg[idx].r = r;
    if (l == r) { seg[idx].v = seg[idx].g = a[l]; seg[idx].cnt = 1; return; }
    int mid = (l + r) / 2;
    build(l, mid, 2*idx); build(mid+1, r, 2*idx+1); pushup(idx);
}

void update(int pos, int val, int idx) {
    if (seg[idx].l == seg[idx].r) { seg[idx].v = seg[idx].g = val; seg[idx].cnt = 1; return; }
    int mid = (seg[idx].l + seg[idx].r) / 2;
    if (pos <= mid) update(pos, val, 2*idx);
    else update(pos, val, 2*idx+1);
    pushup(idx);
}

int queryMin(int l, int r, int idx) {
    if (seg[idx].l == l && seg[idx].r == r) return seg[idx].v;
    int mid = (seg[idx].l + seg[idx].r) / 2;
    if (r <= mid) return queryMin(l, r, 2*idx);
    else if (l > mid) return queryMin(l, r, 2*idx+1);
    else return min(queryMin(l, mid, 2*idx), queryMin(mid+1, r, 2*idx+1));
}

int queryGCD(int l, int r, int idx) {
    if (seg[idx].l == l && seg[idx].r == r) return seg[idx].g;
    int mid = (seg[idx].l + seg[idx].r) / 2;
    if (r <= mid) return queryGCD(l, r, 2*idx);
    else if (l > mid) return queryGCD(l, r, 2*idx+1);
    else return gcd(queryGCD(l, mid, 2*idx), queryGCD(mid+1, r, 2*idx+1));
}

int queryCnt(int l, int r, int val, int idx) {
    if (seg[idx].l == l && seg[idx].r == r) {
        if (seg[idx].g == val) return seg[idx].cnt;
        else return 0;
    }
    int mid = (seg[idx].l + seg[idx].r) / 2;
    if (r <= mid) return queryCnt(l, r, val, 2*idx);
    else if (l > mid) return queryCnt(l, r, val, 2*idx+1);
    else return queryCnt(l, mid, val, 2*idx) + queryCnt(mid+1, r, val, 2*idx+1);
}

void solve(int tc) {

    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build(1, n, 1);
    for (int i = 1, x, y; i <= m; i++) {
        cin >> op >> x >> y;
        if (op == 'C') {
            a[x] = y; update(x, y, 1);
        } else if (op == 'M') {
            cout << queryMin(x, y, 1) << nl;
        } else if (op == 'G') {
            cout << queryGCD(x, y, 1) << nl;
        } else {
            cout << queryCnt(x, y, queryGCD(x, y, 1), 1) << nl;
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