#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+5;
#define nl '\n'
struct E { int v, t, idx; };
int N, M, cnt, grass[MM]; bool vis[MM]; char ch; vector<E> adj[MM];
bool dfs(int u) {
    for (E e : adj[u]) {
        if (vis[e.idx]) continue;
        vis[e.idx] = 1;
        if (e.t == 0) {
            if (grass[e.v] != -1 && grass[e.v] != grass[u]) return 0;
            grass[e.v] = grass[u];
        } else {
            if (e.t == 1 && grass[e.v] != -1 && grass[e.v] == grass[u]) return 0;
            grass[e.v] = !grass[u];
        }
        if (!dfs(e.v)) return 0;
    }
    return 1;
}
void solve(int tc) {
    cin >> N >> M;
    for (int i=1; i<=N; i++) grass[i] = -1;
    for (int i=1, a, b; i<=M; i++) {
        cin >> ch >> a >> b;
        if (ch == 'S') adj[a].push_back({b, 0, i}), adj[b].push_back({a, 0, i});
        else adj[a].push_back({b, 1, i}), adj[b].push_back({a, 1, i});
    }
    for (int i=1; i<=N; i++) {
        if (grass[i] == -1) {
            grass[i] = 0;
            if (!dfs(i)) { cout << 0 << nl; return;  }
            cnt++;
        }
    }
    cout << 1;
    for (int i=1; i<=cnt; i++) cout << 0;
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); int tc = 1; /*cin >> tc;*/ for (int t = 1; t <= tc; t++) solve(t); return 0; }