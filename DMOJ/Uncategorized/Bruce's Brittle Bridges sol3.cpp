#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5+5;
typedef long long ll;
#define nl '\n'
int N, dsu[MM], a[MM], b[MM], t[MM]; ll v[MM]; vector<int> adj[MM];
ll dfs(int u, int pa) {
    ll ret = 0;
    for (int nxt : adj[u]) {
        if (nxt == pa) continue;
        ret = max(ret, dfs(nxt, u));
    }
    return ret + v[u];
}
int fd(int d) {
    if (dsu[d] != d) dsu[d] = fd(dsu[d]);
    return dsu[d];
}
void solve(int tc) {
    cin >> N;
    for (int i=1; i<=N; i++) { cin >> v[i]; dsu[i] = i; }
    for (int i=1; i<N; i++) {
        cin >> a[i] >> b[i] >> t[i];
        if (t[i]>1) {
            int fa = fd(a[i]), fb = fd(b[i]);
            dsu[fa] = fb; v[fb] += v[fa];
        }
    }
    for (int i=1; i<N; i++) {
        if (t[i]==1) {
            int fa = fd(a[i]), fb = fd(b[i]);
            adj[fa].push_back(fb); adj[fb].push_back(fa);
        }
    }
    cout << dfs(fd(1), 0) << nl;
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); int tc = 1; /*cin >> tc;*/ for (int t = 1; t <= tc; t++) solve(t); return 0; }