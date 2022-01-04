#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;
#define nl '\n'
int N, M, a[25][25]; bool vis[25][25];
void solve(int tc) {
    cin >> N >> M; memset(vis, 0, sizeof(vis));
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=M; j++) {
            cin >> a[i][j];
            if (i==1 || j==1 || i==N || j==M) pq.push({a[i][j], {i, j}});
        }
    }
    int ans = 0;
    while (!pq.empty()) {
        pii cur = pq.top(); pq.pop();
        int v = cur.first, r = cur.second.first, c = cur.second.second;
        if (vis[r][c]) continue;
        vis[r][c] = 1; ans += v - a[r][c];
        if (r > 1 && !vis[r-1][c]) pq.push({max(a[r-1][c], v), {r-1, c}});
        if (c > 1 && !vis[r][c-1]) pq.push({max(a[r][c-1], v), {r, c-1}});
        if (r < N && !vis[r+1][c]) pq.push({max(a[r+1][c], v), {r+1, c}});
        if (c < M && !vis[r][c+1]) pq.push({max(a[r][c+1], v), {r, c+1}});
    }
    cout << ans << nl;
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); int tc = 5; /*cin >> tc;*/ for (int t = 1; t <= tc; t++) solve(t); return 0; }