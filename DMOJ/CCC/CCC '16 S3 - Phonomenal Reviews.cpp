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
#define gl(x) getline(cin, (x))
#define sz(x) (int)(x.size())
#define af(x) x.begin(), x.end()
#define ms(x, y) memset(x, y, sizeof(x))
#define mpp make_pair
#define pb push_back
#define AUT auto
//coordinate compression:sort(val.begin(), val.end());
//		val.resize(unique(val.begin(), val.end()) - val.begin());
#define nl '\n'
typedef unsigned long long ull;
const int MOD = 1e9 + 7;
const lld pi = 3.14159265358979323846;

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
int n, m, dis[MM], root, maxd, sz[MM], st = -1; bool pho[MM]; vector<int> adj[MM]; bool vis[MM];

void dfs(int cur, int pa, int d) {
    dis[cur] = d; sz[cur] = 1;
    if (d > maxd && pho[cur]) { maxd = d; root = cur; }
    for (int v : adj[cur]) {
        if (v != pa) {
            dfs(v, cur, d + 1);
            sz[cur] += sz[v]; pho[cur] = max(pho[cur], pho[v]);
        }
    }
    if (pho[cur]) {
        for (int v : adj[cur]) {
            if (v != pa && !pho[v] && !vis[v]) {
                n -= sz[v]; vis[v] = 1;
            }
        }
    }
}

void solve(int tc) {

    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u; cin >> u; u++; pho[u] = 1; st = u;
    }
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v; u++; v++;
        adj[u].push_back(v); adj[v].push_back(u);
    }
    dfs(st, 0, 0); maxd = 0; dfs(root, 0, 0);
    cout << 2 * (n - 1) - maxd << nl;


}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tc = 1;// cin >> tc;
    for (int t = 0; t < tc; t++) solve(t);

    return 0;
}