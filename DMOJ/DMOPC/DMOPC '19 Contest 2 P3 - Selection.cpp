#include <bits/stdc++.h>
using namespace std;
#define nl '\n'

const int MM = 3e5 + 5;
int n, m, g[MM], bit[25][MM];

void update(int tree[], int p, int v) {
    for (; p <= n; p += p&-p) tree[p] += v;
}

int query(int tree[], int p) {
    int ret = 0;
    for (; p >= 1; p -= p&-p) ret += tree[p];
    return ret;
}

void solve(int tc) {

    cin >> n >> m;
    for (int i = 1; i <= n; i++) { cin >> g[i]; update(bit[g[i]], i, 1); }
    for (int i = 1, t, a, b, l, r, c; i <= m; i++) {
        cin >> t;
        if (t == 1) {
            cin >> a >> b;
            update(bit[g[a]], a, -1); update(bit[b], a, 1);
            g[a] = b;
        } else {
            cin >> l >> r >> c;
            int num = 0;
            for (int j = 20; j >= 0; j--) {
                num += query(bit[j], r) - query(bit[j], l - 1);
                if (num >= c) { cout << j << nl; break; }
            }
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