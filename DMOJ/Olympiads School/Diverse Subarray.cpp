#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
#define ms(x, y) memset(x, y, sizeof(x))

const int MM = 2e5 + 5, shift = 1e6, LOG = 18;
int n, q, a[MM], last[2*shift+5], st[MM][LOG+5], pre[MM];

int query(int l, int r) {
    if (l > r) return 0;
    int k = log2(r - l + 1);
    return max(st[l][k], st[r-(1<<k)+1][k]);
}

void solve(int tc) {

    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i]; a[i] += shift;
        pre[i] = min(pre[i-1] + 1, i - last[a[i]]);
        last[a[i]] = i;
        st[i][0] = pre[i];
    }
    for (int j = 1; j <= LOG; j++) {
        for (int i = 1; i + (1 << j) - 1 <= n; i++) {
            st[i][j] = max(st[i][j-1], st[i+(1<<(j-1))][j-1]);
        }
    }
    for (int i = 1, l, r; i <= q; i++) {
        cin >> l >> r;
        int lo = l, hi = r, pos = -1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (mid - pre[mid] + 1 >= l) hi = mid - 1;
            else pos = max(pos, mid), lo = mid + 1;
        }
        if (pos == -1) cout << query(l, r) << nl;
        else cout << max(pos - l + 1, query(pos + 1, r)) << nl;
    }

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}