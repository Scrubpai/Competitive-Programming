#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
int T, G, pts[10]; bool vis[10][10]; int ans = 0;
void rec(int rem) {
    if (rem == 0) {
        bool flag = 1;
        for (int i = 1; i <= 4; i++) {
            if (i != T && pts[T] <= pts[i]) flag = 0;
        }
        if (flag) ans++;
        return;
    }
    for (int i = 1; i < 4; i++) {
        for (int j = i + 1; j < 5; j++) {
            if (!vis[i][j]) {
                vis[i][j] = vis[j][i] = 1;
                pts[i] += 3; rec(rem - 1); pts[i] -= 3;
                pts[j] += 3; rec(rem - 1); pts[j] -= 3;
                pts[i]++; pts[j]++; rec(rem - 1); pts[i]--; pts[j]--;
                vis[i][j] = vis[j][i] = 0;
                return;
            }
        }
    }
}
void solve(int tc) {
    cin >> T >> G;
    for (int i = 0; i < G; i++) {
        int a, b, sa, sb; cin >> a >> b >> sa >> sb; vis[a][b] = vis[b][a] = 1;
        if (sa > sb) pts[a] += 3;
        else if (sa < sb) pts[b] += 3;
        else pts[a]++, pts[b]++;
    }
    rec(6 - G);
    cout << ans << nl;
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); int tc = 1; /*cin >> tc;*/ for (int t = 1; t <= tc; t++) solve(t); return 0; }