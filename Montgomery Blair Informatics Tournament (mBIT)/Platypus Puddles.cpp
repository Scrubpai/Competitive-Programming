#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;
#define nl '\n'

int n, a[1005][1005]; priority_queue<pii, vector<pii>, greater<pii>> pq; ll ans; bool vis[1005][1005];

void solve(int tc) {

    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            if (i == 1 || j == 1 || i == n || j == n) {
                pq.push({a[i][j], {i, j}});
            }
        }
    }
    while (!pq.empty()) {
        pii cur = pq.top(); pq.pop();
        int v = cur.first, r = cur.second.first, c = cur.second.second;
        if (vis[r][c]) continue;
        vis[r][c] = 1; ans += v - a[r][c];

        if (r > 1 && !vis[r-1][c]) pq.push({max(a[r-1][c], v), {r-1, c}});
        if (c > 1 && !vis[r][c-1]) pq.push({max(a[r][c-1], v), {r, c-1}});
        if (r < n && !vis[r+1][c]) pq.push({max(a[r+1][c], v), {r+1, c}});
        if (c < n && !vis[r][c+1]) pq.push({max(a[r][c+1], v), {r, c+1}});
    }
    cout << ans;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}