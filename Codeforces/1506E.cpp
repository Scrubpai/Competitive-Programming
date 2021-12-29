#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5+5;
#define nl '\n'
int n;
void solve(int tc) {
    cin >> n;
    vector<int> q(n), mn, mx, vis(n+1);
    stack<int> st;
    queue<int> qu;
    for (int i=0, j=0; i<n; i++) {
        cin >> q[i];
        if (!i || q[i] != q[i-1]) mn.push_back(q[i]), mx.push_back(q[i]), vis[q[i]] = 1;
        else {
            while (j<q[i]) {
                j++;
                if (!vis[j]) st.push(j), qu.push(j);
            }
            mn.push_back(qu.front()); qu.pop();
            mx.push_back(st.top()); st.pop();
        }
    }
    for (int i : mn) cout << i << " ";
    cout << nl;
    for (int i : mx) cout << i << " ";
    cout << nl;
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int tc = 1; cin >> tc; for (int t = 1; t <= tc; t++) solve(t); return 0; }