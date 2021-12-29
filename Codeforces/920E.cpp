#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5+5;
#define nl '\n'
int n, m; set<int> adj[MM], unvis; vector<int> ans;
void dfs(int x, set<int> &st) {
    st.insert(x);
    unvis.erase(x);
    int cur = -1;
    while (true) {
        auto it = unvis.upper_bound(cur);
        if (it == unvis.end()) break;
        cur = *it;
        if (adj[x].count(cur)) { adj[x].erase(cur); continue; }
        dfs(cur, st);
    }
}
void solve(int tc) {
    cin >> n >> m;
    for (int i=1, a, b; i<=m; i++) {
        cin >> a >> b;
        adj[a].insert(b);
        adj[b].insert(a);
    }
    for (int i=1; i<=n; i++) unvis.insert(i);
    set<int> s;
    for (int i=1; i<=n; i++) {
        if (unvis.count(i)) {
            s.clear();
            dfs(i, s);
            ans.push_back(s.size());
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << nl;
    for (int x : ans) cout << x << ' ';
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int tc = 1; /*cin >> tc;*/ for (int t = 1; t <= tc; t++) solve(t); return 0; }