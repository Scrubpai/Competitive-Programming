#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define nl '\n'
const int MM = 2e5 + 5;
ll M, N, Q, bit1[MM], bit2[MM], l, r, x;
void update(int p, ll bit[], ll v) { for (; p <= N; p += p&-p) bit[p] += v; }
ll query(int p, ll bit[]) { ll ret = 0; for (; p >= 1; p -= p&-p) ret += bit[p]; return ret; }
ll prefix(int p) { return query(p, bit1) * p + query(p, bit2); } //if v is the value in bit1, assume that all values [1, p] equals v. Since the assumption is not true, adjust the answer using query2
void upd(int l, int r, ll v) { update(l, bit1, v); update(r+1, bit1, -v); update(l, bit2, -v*(l-1)); update(r+1, bit2, v*r); }
void solve(int tc) {
    cin >> M >> N >> Q;
    for (int i = 1, a; i <= N; i++) { cin >> a; upd(i, i, a); }
    for (int i = 1, op; i <= Q; i++) {
        cin >> op;
        if (op == 1) { cin >> l >> r >> x; upd(l, r, x); }
        else { cin >> l >> r; cout << ((prefix(r) - prefix(l-1)) % M + M) % M << nl; }
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}