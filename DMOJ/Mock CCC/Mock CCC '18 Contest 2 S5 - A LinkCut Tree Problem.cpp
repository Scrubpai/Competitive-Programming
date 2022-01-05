#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<int, ll> pii;
#define endl '\n'
#define INF 0x3f3f3f3f
#define gl(x) getline(cin, (x))
#define sz(x) (int)(x.size())
#define af(x) x.begin(), x.end()
#define ms(x, y) memset(x, y, sizeof(x))
#define lb lower_bound
#define ub upper_bound
#define mpp make_pair
#define pb push_back
#define f first
#define s second
#define nl '\n'
const int NM = (int)1e3 + 5;

struct E { 
    int idx, v; ll w;
};
struct E2 { 
    int idx, u, v; ll w;
    bool operator < (const E2&other) const {
        return this->w > other.w;
    }
};

int N, M, Q; ll w; ll x; int dsu[NM];
vector<E2> ed;
vector<E> adj[NM]; bool vis[NM];
pair<pi, ll> edges[5001];

int Find(int x) {
    if (dsu[x]==x) return x;
    else return dsu[x] = Find(dsu[x]);
}

void dfs(int cur, ll weight) {
    vis[cur] = true;
    for (E p : adj[cur]) {
        if (p.w<weight) continue;
        if (!vis[p.v]) {
            dfs(p.v, weight);
        }
    }
}

void updateGraph() {
    sort(ed.begin(), ed.end()); 
    for (int i=1; i<=N; i++) dsu[i] = i;
    for (E2 e : ed) {
        int fu = Find(e.u); int fv = Find(e.v);
        if (fu!=fv) {
            dsu[fu] = fv;  
            adj[e.u].pb({e.idx, e.v, e.w}); adj[e.v].pb({e.idx, e.u, e.w});
        }
    }
}

void solve() {

    cin >> N >> M;
    for (int i=1, u, v; i<=M; i++) {
        cin >> u >> v >> w;
        ed.pb({i, u, v, w}); 
    }
    updateGraph();

    cin >> Q;
    for (int q=0, n, m, a, b; q<Q; q++) { 
        cin >> n;
        if (n==1) {
            cin >> m >> x;

            for (int i=0; i<ed.size(); i++) {
                if (ed[i].idx==m) ed[i].w=x;
            }
            for (int i=1; i<=N; i++) { adj[i].clear(); }
            updateGraph();
        } else {
            cin >> a >> b >> w;
            for (int j=1; j<=N; j++) vis[j] = false;
            dfs(a, w);
            if (vis[b]) cout << 1 << nl;
            else cout << 0 << nl;
        }
    }

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}