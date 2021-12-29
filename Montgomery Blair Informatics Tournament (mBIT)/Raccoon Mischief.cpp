#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define nl '\n'

const int MM = 1e5 + 5;
struct Q {
    int l, r, x;
};
int n, q, psa[MM], a[MM], ans[MM]; set<int> st; vector<Q> queries;


void solve(int tc) {

    cin >> n >> q;
    for (int i = 1; i <= n; i++) { cin >> a[i]; ans[i] = a[i]; st.insert(i); }
    for (int i = 1, l, r, x; i <= q; i++) {
        cin >> l >> r >> x;
        psa[l]++; psa[r+1]--;
        queries.push_back({l, r, x});
    }
    for (int i = 1; i <= n; i++) psa[i] += psa[i-1];
    for (int i = q - 1; i >= 0; i--) {
        int l = queries[i].l, r = queries[i].r, x = queries[i].x;
        if (st.empty()) break;
        auto it = st.lower_bound(l);
        while (it != st.end()) {
            int idx = *it;
            if (idx > r) break;
            if (a[idx] > 0) {
                if (psa[idx] % 2 == 0) {
                    ans[idx] = x;
                } else {
                    ans[idx] = 0;
                }
            } else {
                if (psa[idx] % 2 == 0) {
                    ans[idx] = 0;
                } else {
                    ans[idx] = x;
                }
            }
            st.erase(*it);
            if (st.empty()) break;
            it = st.lower_bound(l);
        }
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << ' ';

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}