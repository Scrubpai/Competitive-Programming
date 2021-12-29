#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
int n, v; vector<pair<char, int>> a; vector<int> ans; char c; stack<int> st;
void solve(int tc) {
    cin >> n;
    for (int i = 0; i < 2*n; i++) {
        cin >> c;
        if (c == '+') a.push_back({c, 0});
        else { cin >> v; a.push_back({c, v}); }
    }
    reverse(a.begin(), a.end());
    for (pair<char, int> p : a) {
        if (p.first == '+') {
            if (st.empty()) { cout << "NO" << nl; return; }
            else { ans.push_back(st.top()); st.pop(); }
        } else {
            if (!st.empty() && p.second > st.top()) { cout << "NO" << nl; return; }
            st.push(p.second);
        }
    }
    reverse(ans.begin(), ans.end());
    cout << "YES" << nl;
    for (int x : ans) cout << x << ' ';
}
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc = 1;// cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}