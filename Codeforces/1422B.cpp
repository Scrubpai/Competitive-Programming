#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
typedef long long ll;
typedef pair<int, int> pii;
#define LL_INF 0x3f3f3f3f3f3f3f3f

int n, m; ll a[105][105]; set<pii> st;

void solve(int tc) {

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    ll ans = 0;
    for (int i = 0; i < (n+1)/2; i++) {
        for (int j = 0; j < (m+1)/2; j++) {
            int r1 = i, c1 = j, r2 = i, c2 = m - j - 1, r3 = n - i - 1, c3 = j, r4 = n - i - 1, c4 = m - j - 1;
            st.clear(); st.insert({r1, c1}); st.insert({r2, c2}); st.insert({r3, c3}); st.insert({r4, c4});
            ll v = 0, add = LL_INF;
            for (pii p : st) v += abs(a[p.first][p.second] - a[r1][c1]);
            add = min(add, v); v = 0;
            for (pii p : st) v += abs(a[p.first][p.second] - a[r2][c2]);
            add = min(add, v); v = 0;
            for (pii p : st) v += abs(a[p.first][p.second] - a[r3][c3]);
            add = min(add, v); v = 0;
            for (pii p : st) v += abs(a[p.first][p.second] - a[r4][c4]);
            add = min(add, v); v = 0;
            ans += add;
        }
    }
    cout << ans << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int tc = 1; cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}