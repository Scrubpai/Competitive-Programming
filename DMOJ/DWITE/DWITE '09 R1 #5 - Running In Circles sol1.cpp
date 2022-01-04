#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
const long long MAXN = numeric_limits<long long>::max();
typedef long long ll;

int N; int pre[101]; int vis[101]; vector<int> adj[101]; bool cycle; int finish;

int dfs(int cur, int i) {
    vis[cur] = 1;

    for (int v: adj[cur]) {
        if (!cycle) {
            if (vis[v]==1) {
                finish = v; cycle = true; i = cur; break;
            } else if (vis[v]==0) {
                pre[v] = cur; i = dfs(v, i);
            }
        }
    }

    vis[cur] = 2;
    return i;
}

void solve() {

    for (int i=0, a, b; i<5; i++) {
        for (int j=1; j<=100; j++) { pre[j] = 0; vis[j] = 0; adj[j].clear(); }
        cin >> N; cycle = false; finish = 0;
        for (int j=0; j<N; j++) {
            cin >> a >> b;
            adj[a].push_back(b);
        }

        int cur = dfs(1, 1); int cnt = 0;
        for (int j=cur; j!=pre[finish]; j=pre[j]) cnt++;
        cout << cnt << endl;
    }

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}