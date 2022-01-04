#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define nl '\n'
#define ms(x, y) memset(x, y, sizeof(x))
#define INF 0x3f3f3f3f

struct E {
    int v, t, h;
    bool operator < (const E& other) const {
        return this->t > other.t;
    }
};
int N, K, M, dis[2005][205], A, B; vector<E> adj[2005]; priority_queue<E> pq;

void solve(int tc) {

    cin >> K >> N >> M; ms(dis, INF);
    for (int i = 0, a, b, t, h; i < M; i++) {
        cin >> a >> b >> t >> h;
        adj[a].push_back({b, t, h});
        adj[b].push_back({a, t, h});
    }
    cin >> A >> B;
    dis[A][0] = 0; pq.push({A, 0, 0});
    while (!pq.empty()) {
        E cur = pq.top(); pq.pop();
        int d = cur.t, w = cur.h, v = cur.v;
        if (d > dis[v][w]) continue;
        for (E nxt : adj[v]) {
            if (nxt.h + w >= K) continue;
            if (dis[nxt.v][nxt.h+w] > d + nxt.t) {
                dis[nxt.v][nxt.h+w] = d + nxt.t;
                pq.push({nxt.v, d + nxt.t, nxt.h + w});
            }
        }
    }
    int ans = INF;
    for (int i = 0; i < K; i++) ans = min(ans, dis[B][i]);
    if (ans == INF) cout << -1 << nl;
    else cout << ans << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}