#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
#define nl '\n'
#define f first
#define s second
int N, M, Q, x[51]; pi bag[51];
void solve(int tc) {
    cin >> N >> M >> Q;
    for (int i=1; i<=N; i++) cin >> bag[i].s >> bag[i].f;
    for (int i=1; i<=M; i++) cin >> x[i];
    sort(bag+1, bag+1+N, greater<>());
    for (int i=1, l, r; i<=Q; i++) {
        cin >> l >> r;
        multiset<int> st;
        for (int j=1; j<=M; j++) {
            if (j>=l && j<=r) continue;
            st.insert(x[j]);
        }
        int ans = 0;
        for (int j=1; j<=N; j++) {
            auto it = st.lower_bound(bag[j].s);
            if (it != st.end()) ans += bag[j].f, st.erase(it);
        }
        cout << ans << nl;
    }
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int tc = 1; /*cin >> tc;*/ for (int t = 1; t <= tc; t++) solve(t); return 0; }