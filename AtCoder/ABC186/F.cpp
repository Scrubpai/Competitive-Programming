#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5 + 5;
typedef long long ll;
#define nl '\n'
int H, W, M, lft[MM], up[MM], bit[MM]; bool vis[MM]; vector<int> row[MM];
struct pt {
    int x, y;
} pts[MM];
void update(int p) { for (; p <= W; p += p&-p) bit[p]++; }
int query(int p) { int ret = 0; for (; p >= 1; p -= p&-p) ret += bit[p]; return ret; }
void solve(int tc) {
    cin >> H >> W >> M;
    for (int i = 1; i <= H; i++) lft[i] = W+1;
    for (int i = 1; i <= W; i++) up[i] = H+1;
    for (int i = 1, x, y; i <= M; i++) {
        cin >> x >> y;
        pts[i] = {x, y};
        row[x].push_back(y);
    }
    for (int i = 1; i <= M; i++) {
        lft[pts[i].x] = min(lft[pts[i].x], pts[i].y);
        up[pts[i].y] = min(up[pts[i].y], pts[i].x);
    }
    ll ans = 0;
    //move right then move down
    for (int i = 1; i < lft[1]; i++) ans += up[i] - 1;
    //move down then move right
    for (int i = 1; i < up[1]; i++) {
        //Only if there is obstacle above in the range [1, lft[i])
        ans += query(min(lft[1] - 1, lft[i] - 1));
        ans += max(lft[i] - lft[1], 0);
        for (int y : row[i]) {
            if (!vis[y] && y < lft[1]) update(y), vis[y] = 1;
        }
    }
    cout << ans << nl;
}
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}