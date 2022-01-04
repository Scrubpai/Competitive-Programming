#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 200001;
typedef pair<int, int> pi;
typedef long long ll;
#define endl '\n'
#define INF 0x3f3f3f3f
#define gl(x) getline(cin, (x))
#define sz(x) (int)(x.size())
#define af(x) x.begin(), x.end();
#define ms(x, y) memset(x, y, sizeof(x))
#define lb lower_bound
#define ub upper_bound
#define mpp make_pair
#define pb push_back
#define sz(a) sizeof(a)/sizeof(a[0])

struct E {
    int v; ll p;
};

int N, M; int dsu[MAXN]; pair<ll, pi> p[MAXN]; vector<E> adj[MAXN]; ll dis[MAXN];

int Find(int x) {
    if (dsu[x]==x) return x;
    else return dsu[x] = Find(dsu[x]);
}

void Union(int x, int y) {
    dsu[Find(x)] = Find(y);
}

void dfs(int cur, int par) {
    for (E e : adj[cur]) {
        if (e.v!=par) {
            dis[e.v] = min(e.p, dis[cur]);
            dfs(e.v, cur);
        }
    }
}

void solve() {

    cin >> N >> M;
    for (int i=1; i<=N; i++) dsu[i] = i;

    for (int i=0, u, v, w; i<M; i++) {
        cin >> u >> v >> w;
        p[i] = {w, {u, v}};
    }

    sort(p, p+M, greater<pair<ll, pi> >());

    for (int i=0; i<M; i++) {
        int u = p[i].second.first; int v = p[i].second.second; ll w = p[i].first;
        if (Find(u)!=Find(v)) {
            Union(u, v);
            adj[u].pb({v, w}); adj[v].pb({u, w});
        }
    }

    cout << 0 << endl;
    ms(dis, 0x3f); dfs(1, 0);
    for (int i=2; i<=N; i++) {
        cout << dis[i] << endl;
    }

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}