//why tle lol
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<string> vs;
typedef complex<double> pnt;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<pii, pii> pp;
typedef double ld;
typedef long double lld;
#define INF 0x3f3f3f3f // for int
#define LL_INF 0x3f3f3f3f3f3f3f3f // for ll
#define ms(x, y) memset(x, y, sizeof(x))
//coordinate compression:sort(val.begin(), val.end());
//		val.resize(unique(val.begin(), val.end()) - val.begin());
#define nl '\n'
typedef unsigned long long ull;
const lld pi = 3.14159265358979323846;
const int MOD = 1e9 + 7;

ll gcd(ll a, ll b){return b == 0 ? a : gcd(b, a % b);}
ll lcm(ll a, ll b){return a*b/gcd(a,b);}
ll pwmd(ll b, ll exp) {
    ll ret = 1;
    while (exp > 0) {
        if (exp % 2 == 1) ret = (ret * b) % MOD;
        exp /= 2;
        b = (b * b) % MOD;
    }
    return ret;
}

const int MM = 1e5 + 5;
const int MX = 16;
int N, M, LCA[MM][MX+5], sz[MM], dep[MM], pre[MM], best[MM]; vector<vector<int>> adj; bool vis[MM];

void dfs(int x, int pa) {
    sz[x] = 1;
    for (int v : adj[x]) {
        if (!vis[v] && v != pa) {
            dfs(v, x);
            sz[x] += sz[v];
        }
    }
}

int getCentroid(int v, int pa, int n) {
    for (int x : adj[v]) {
        if (x == pa || vis[x]) continue;
        if (sz[x] > n / 2) return getCentroid(x, v, n);
    }
    return v;
}

void init_centroid(int cur, int pa) {
    dfs(cur, pa);
    int c = getCentroid(cur, -1, sz[cur]);
    vis[c] = 1; pre[c] = pa;

    for (int x : adj[c]) {
        if (!vis[x]) {
            init_centroid(x, c);
        }
    }
}

void init() {
    for (int j = 1; j <= MX; j++) {
        for (int i = 1; i <= N; i++) {
            int par = LCA[i][j-1];
            if (par != -1) {
                LCA[i][j] = LCA[par][j-1];
            }
        }
    }
}

int lca(int a, int b) {
    if (dep[a] < dep[b]) swap(a, b); //dep[a] >= dep[b]
    int d = dep[a] - dep[b];
    while (d > 0) {
        int i = log2(d);
        a = LCA[a][i];
        d -= (1 << i);
    }
    if (a == b) return a;
    for (int i = MX; i >= 0; i--) {
        if (LCA[a][i] != -1 && LCA[b][i] != -1 && LCA[a][i] != LCA[b][i]) a = LCA[a][i], b = LCA[b][i];
    }
    return LCA[a][0];
}

void dfs0(int cur, int pa) {
    LCA[cur][0] = pa;
    for (int v : adj[cur]) {
        if (v != pa) {
            dep[v] = dep[cur] + 1;
            dfs0(v, cur);
        }
    }
}

int dist(int u, int v) {
    return dep[u] + dep[v] - 2 * dep[lca(u, v)];
}

void update(int u) {
    int x = u;
    while (x != -1) {
        best[x] = min(best[x], dist(x, u));
        x = pre[x];
    }
}

int query(int u) {
    int x = u, ret = INF;
    while (x != -1) {
        ret = min(ret, dist(u, x) + best[x]);
        x = pre[x];
    }
    return ret;
}

void solve(int tc) {

    cin >> N >> M; adj = vector<vector<int> >(N+1, vector<int>());
    for (int i = 1; i <= N; i++) { for (int j = 1; j <= MX; j++) LCA[i][j] = -1; }
    for (int i = 1; i <= N; i++) { best[i] = 2e5; pre[i] = -1; }
    for (int i = 1, a, b; i < N; i++) {
        cin >> a >> b;
        adj[a].push_back(b); adj[b].push_back(a);
    }
    dep[1] = 1; dfs0(1, -1); init(); init_centroid(1, -1);
    //1st node is red; update node 1
    update(1);
    while (M--) {
        int t, v; cin >> t >> v;
        if (t == 1) {
            update(v);
        } else if (t == 2) {
            cout << query(v) << nl;
        }
    }

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);

    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
*/