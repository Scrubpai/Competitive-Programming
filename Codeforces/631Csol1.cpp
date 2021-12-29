#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5 + 5;
#define nl '\n'
int n, m, a[MM], bit[MM], q[MM]; multiset<int> st;
void update(int p, int v) { for (; p <= n; p += p&-p) bit[p] = max(bit[p], v); }
int query(int p) { int ret = 0; for (; p >= 1; p -= p&-p) ret = max(ret, bit[p]); return ret; }
void solve(int tc) {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        st.insert(a[i]);
    }
    for (int i = 1, t, r; i <= m; i++) {
        cin >> t >> r;
        q[i] = t;
        update(n-r+1, i);
    }
    for (int i = n; i >= 1; i--) {
        int idx = query(n-i+1);
        if (q[idx] == 1) a[i] = *st.rbegin();
        else if (q[idx] == 2) a[i] = *st.begin();
        st.erase(st.lower_bound(a[i]));
    }
    for (int i = 1; i <= n; i++) cout << a[i] << ' ';
}
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}