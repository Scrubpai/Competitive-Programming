#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
typedef long long ll;
const int MM = 2e5 + 5;
const int MX = 17;

int n, q, l, r; ll a[MM], v, st[MM][MX];

void init() {
    for (int j = 1; j <= MX; j++) {
        for (int i = 0; i <= n - (1 << j); i++) {
            st[i][j] = min(st[i][j-1], st[i+(1<<(j-1))][j-1]);
        }
    }
}

ll query(int x, int y) {
    int i = log2(y - x + 1);
    return min(st[x][i], st[y-(1<<i)+1][i]);
}

void solve(int tc) {

    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        st[i][0] = a[i];
    }
    init();
    while (q--) {
        cin >> v >> l >> r; l--; r--;
        while (l <= r) {
            int nxt = r+1, lo = l, hi = r;
            while (lo <= hi) {
                int mid = (lo + hi) / 2;
                if (query(l, mid) > v) lo = mid + 1;
                else nxt = min(nxt, mid), hi = mid - 1;
            }
            if (nxt <= r) v %= a[nxt];
            l = nxt + 1;
        }
        cout << v << nl;
    }

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}