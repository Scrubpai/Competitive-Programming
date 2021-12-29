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
const int MX = 17;

int N, M, LCA[MM][MX+5], dep[MM], lo[MM], hi[MM], cnt; vector<int> adj[MM], d[MM];

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

void dfs(int cur, int pa) {
    cnt++; lo[cur] = cnt;
    d[dep[cur]].push_back(cnt);
    for (int v : adj[cur]) {
        if (v != pa) {
            dep[v] = dep[cur] + 1;
            dfs(v, cur);
        }
    }
    hi[cur] = cnt;
}

int getPar(int u, int d) {
    while (d > 0) {
        int i = log2(d);
        u = LCA[u][i];
        if (u == -1) return -1;
        d -= (1 << i);
    }
    return u;
}

void solve(int tc) {

    cin >> N; ms(LCA, -1);
    for (int i = 1, r; i <= N; i++) {
        cin >> r;
        if (r) {
            LCA[i][0] = r;
            adj[r].push_back(i); adj[i].push_back(r);
        }
    }
    for (int i = 1; i <= N; i++) {
        if (LCA[i][0] == -1) {
            dep[i] = 1;
            dfs(i, -1);
        }
    }
    init();
    cin >> M;
    while (M--) {
        int v, p; cin >> v >> p;
        int u = getPar(v, p);
        if (u == -1) { cout << 0 << " "; continue; }
        int ans = upper_bound(d[dep[v]].begin(), d[dep[v]].end(), hi[u]) - d[dep[v]].begin();
        ans = ans - (lower_bound(d[dep[v]].begin(), d[dep[v]].end(), lo[u]) - d[dep[v]].begin());
        ans--;
        cout << ans << " ";
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