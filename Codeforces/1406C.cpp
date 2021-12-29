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
int n, x, y, sz[MM], par[MM], c1, c2; vector<int> adj[MM];

void dfs(int u, int pa) {
    sz[u] = 1; par[u] = pa;
    for (int v : adj[u]) {
        if (v != pa) {
            dfs(v, u);
            sz[u] += sz[v];
        }
    }
}

int dfs2(int u, int pa) {
    par[u] = pa;
    for (int v : adj[u]) {
        if (v == pa || v == c2) continue;
        return dfs2(v, u);
    }
    return u;
}

int getCentroid(int u, int pa) {
    for (int v : adj[u]) {
        if (v != pa && sz[v] > n / 2) return getCentroid(v, u);
    }
    return u;
}

void solve(int tc) {

    cin >> n;
    for (int i = 1; i <= n; i++) { adj[i].clear(); sz[i] = 0; }
    for (int i = 1; i < n; i++) {
        cin >> x >> y;
        adj[x].push_back(y); adj[y].push_back(x);
    }
    dfs(1, -1);
    c1 = getCentroid(1, -1); c2 = -1; int mx = n - sz[c1];
    for (int v : adj[c1]) {
        if (v == par[c1]) continue;
        mx = max(mx, sz[v]);
    }
    for (int v : adj[c1]) {
        if (v == par[c1]) continue;
        if (n - sz[v] == mx) { c2 = v; }
    }
    if (c2 == -1) { cout << x << " " << y << nl << x << " " << y << nl; return; }
    int leaf = dfs2(c1, -1);
    cout << leaf << " " << par[leaf] << nl;
    cout << c2 << " " << leaf << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tc = 1; cin >> tc;
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