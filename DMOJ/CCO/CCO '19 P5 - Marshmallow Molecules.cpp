#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+5;
typedef long long ll;
#define nl '\n'
int N, M; set<int> adj[MM];
void solve(int tc) {
    cin >> N >> M;
    for (int i=1, a, b; i<=M; i++) {
        cin >> a >> b;
        adj[a].insert(b);
    }
    ll ans = 0;
    for (int i=1, v; i<=N; i++) {
        if (adj[i].empty()) continue;
        ans += (ll)adj[i].size();
        auto it = adj[i].begin(); v = *it;
        adj[i].erase(it);
        if (adj[v].size() < adj[i].size()) adj[v].swap(adj[i]);
        if (!adj[i].empty()) adj[v].insert(adj[i].begin(), adj[i].end());
    }
    cout << ans << nl;
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int tc = 1; /*cin >> tc;*/ for (int t = 1; t <= tc; t++) solve(t); return 0; }