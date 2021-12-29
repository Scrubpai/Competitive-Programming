#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
void solve(int tc) {
    int n; cin >> n;
    vector<int> a(n), ans(n); stack<int> st;
    for (int i=0; i<n; i++) {
        st.push(i);
        cin >> a[i];
        for (int j=0; j<a[i] && !st.empty(); j++) {
            if (st.top() <= i-a[i]) break;
            ans[st.top()] = 1;
            st.pop();
        }
    }
    for (int i=0; i<n; i++) cout << ans[i] << ' ';
    cout << nl;
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int tc = 1; cin >> tc; for (int t = 1; t <= tc; t++) solve(t); return 0; }