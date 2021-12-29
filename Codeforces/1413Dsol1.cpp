#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5 + 5;
#define nl '\n'
int n, ans[2*MM], p[2*MM]; char c; set<int> pos; stack<int> st;
void solve(int tc) {
    cin >> n;
    for (int i = 1; i <= 2 * n; i++) {
       cin >> c;
       if (c == '+') pos.insert(i);
       else {
           cin >> p[i];
           //monotonically decreasing stack. Find first one to the left that's greater than p; cant place before it
           while (!st.empty() && p[i] > p[st.top()]) st.pop();
           if (!st.empty()) {
               auto it = pos.lower_bound(st.top());
               if (it == pos.end()) { cout << "NO" << nl; return; }
               else { ans[*it] = p[i]; pos.erase(*it); }
           } else {
               auto it = pos.lower_bound(1);
               if (it == pos.end()) { cout << "NO" << nl; return; }
               else { ans[*it] = p[i]; pos.erase(*it); }
           }
           st.push(i);
       }
    }
    cout << "YES" << nl;
    for (int i = 1; i <= 2 * n; i++) {
        if (ans[i]) cout << ans[i] << ' ';
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc = 1;// cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}