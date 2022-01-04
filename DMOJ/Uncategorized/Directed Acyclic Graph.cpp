#include <bits/stdc++.h>
using namespace std;
#define nl '\n'

int n, a[1005][1005], in[1005]; bool vis[1005];

void solve(int tc) {

    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j]; vis[i] = 1; vis[j] = 1;
            if (a[i][j]) in[j]++;
        }
    }
    queue<int> q;
    int nodes = 0;
    for (int i = 1; i <= n; i++) {
        if (vis[i] && !in[i]) q.push(i);
        if (vis[i]) nodes++;
    }
    int cnt = 0;
    while (!q.empty()) {
        int cur = q.front(); q.pop(); cnt++;
        for (int i = 1; i <= n; i++) {
            if (a[cur][i]) {
                in[i]--;
                if (!in[i]) q.push(i);
            }
        }
    }
    if (cnt != nodes) cout << "NO" << nl;
    else cout << "YES" << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}