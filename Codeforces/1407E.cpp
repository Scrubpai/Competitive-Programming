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

const int MM = 5e5 + 5;
int n, m, color[MM], dis[MM]; vector<pii> adj[MM]; bool vis[MM]; queue<int> q;

void solve(int tc) {

    cin >> n >> m; ms(color, -1); ms(dis, -1); color[n] = 1;
    for (int i = 1, u, v, t; i <= m; i++) {
        cin >> u >> v >> t;
        adj[v].push_back({u, t});
    }
    q.push(n); vis[n] = 1; dis[n] = 0;
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (pii p : adj[cur]) {
            if (color[p.first] == -1) color[p.first] = (p.second ^ 1);
            else {
                if (!vis[p.first] && color[p.first] == p.second) {
                    dis[p.first] = dis[cur] + 1;
                    q.push(p.first); vis[p.first] = 1;
                }
            }
        }
    }
    cout << dis[1] << nl;
    for (int i = 1; i <= n; i++) {
        if (color[i] == -1) cout << 1;
        else cout << color[i];
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