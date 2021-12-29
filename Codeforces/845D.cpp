#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
int n, t, cur, lmt = 1e9, cnt;
void solve(int tc) {
    cin >> n >> t >> cur;
    int ans = 0; stack<int> st;
    for (int i = 1; i < n; i++) {
        cin >> t;
        if (t == 1) {
            cin >> cur;
        } else if (t == 2) {
            ans += cnt;
            cnt = 0;
        } else if (t == 3) {
            cin >> lmt;
            st.push(lmt);
        } else if (t == 4) {
            cnt = 0;
        } else if (t == 5) {
            lmt = 1e9;
            while (!st.empty()) st.pop();
        } else {
            cnt++;
        }
        while (!st.empty() && st.top() < cur) st.pop(), ans++;
    }
    cout << ans << nl;
}
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}