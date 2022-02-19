#include <bits/stdc++.h>
using namespace std;
const int MM = 300;
int N, D, c[MM], dp[MM][2*MM+1], lc[MM], rc[MM];
void dfs(int u) {
    if (lc[u] != -1) dfs(lc[u]);
    if (rc[u] != -1) dfs(rc[u]);
    dp[u][N] = 1;
    if (lc[u] == -1) {
        dp[u][c[u]+N] = 0;
        return;
    } else if (rc[u] == -1) {
        for (int i=-N; i<=N; i++) {
            dp[u][c[u]+i+N] = min(dp[u][c[u]+i+N], dp[lc[u]][i+N]);
        }
    } else {
        for (int i=-N; i<=N; i++) {
            for (int j=-N; j<=N; j++) {
                dp[u][c[u]+i+j+N] = min(dp[u][c[u]+i+j+N], dp[lc[u]][i+N] + dp[rc[u]][j+N]);
            }
        }
    }

}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N >> D; memset(lc, -1, sizeof(lc)); memset(rc, -1, sizeof(rc)); memset(dp, 0x3f, sizeof(dp));
    for (int i=0, id, C; i<N; i++) {
        cin >> id >> c[id] >> C;
        if (!c[id]) c[id]--;
        for (int j=0, v; j<C; j++) {
            cin >> v;
            if (lc[id] == -1) lc[id] = v;
            else rc[id] = v;
        }
    }
    dfs(0);
    cout << (dp[0][D+N]>1e9?-1:dp[0][D+N]) << '\n';
}