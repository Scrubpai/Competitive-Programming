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
const ll MOD = 1e9 + 7;

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

int n, m, dsu[51], deg[51]; vector<int> adj[51]; bool cycle = 0, vis[51];

int Find(int x) {
    if (dsu[x] == x) return x;
    else return dsu[x] = Find(dsu[x]);
}

void dfs(int cur, int pa) {
    vis[cur] = 1;
    for (int v : adj[cur]) {
        if (v == pa) continue;
        if (vis[v] == 1) cycle = 1;
        else if (!vis[v]) dfs(v, cur);
    }
    vis[cur] = 2;
}

void solve(int tc) {

    cin >> n >> m; int cnt = 1;
    if (n == 1 && m == 0) { cout << "YES" << nl << 1 << nl << 1 << " " << 1 << nl; return; }
    if (m > n) { cout << "NO" << nl; return; }
    for (int i = 1; i <= n; i++) dsu[i] = i;
    for (int i = 1, u, v; i <= m; i++) {
        cin >> u >> v; deg[u]++; deg[v]++;
        int fu = Find(u), fv = Find(v);
        adj[u].push_back(v); adj[v].push_back(u);
        if (fu != fv) {
            dsu[fu] = fv; cnt++;
        }
    }
    if (cnt == n) {
        bool flag = 1;
        for (int i = 1; i <= n; i++) {
            if (deg[i] != 2) {
                flag = 0;
            }
        }
        if (flag) { cout << "YES" << nl << 0 << nl; return; }
    }
    for (int i = 1; i <= n; i++) {
        if (deg[i] > 2) { cout << "NO" << nl; return; }
        if (!vis[i]) {
            dfs(i, 0);
        }
    }
    if (cycle) { cout << "NO" << nl; return; }
    cout << "YES" << nl << n - m << nl;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int fu = Find(i), fv = Find(j);
            if (deg[i] >= 2 || deg[j] >= 2) continue;
            if (fu != fv) {
                dsu[fu] = fv;
                deg[i]++; deg[j]++;
                cout << i << " " << j << nl;
            }
        }
    }
    int a = -1, b = -1;
    for (int i = 1; i <= n; i++) {
        if (deg[i] != 2) {
            if (a == -1) a = i;
            else b = i;
        }
    }
    cout << a << " " << b << nl;

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