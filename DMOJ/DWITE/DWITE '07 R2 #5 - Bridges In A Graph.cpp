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
#define INF 0x3f3f3f3f // for int
#define LL_INF 0x3f3f3f3f3f3f3f3f // for ll
#define gl(x) getline(cin, (x))
#define sz(x) (int)(x.size())
#define af(x) x.begin(), x.end()
#define ms(x, y) memset(x, y, sizeof(x))
#define lb lower_bound
#define ub upper_bound
#define mpp make_pair
#define pb push_back
#define nl '\n'
typedef unsigned long long ull;
const int MOD = 10;

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

int T = 5, n, m, adj[105][105], u[105], v[105]; bool vis[105]; int cnt;

void bfs() {
    queue<int> q; vis[1] = true; q.push(1); cnt = 1;
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (int v = 1; v <= 100; v++) {
            if (adj[cur][v] && !vis[v]) {
                vis[v] = true; q.push(v); cnt++;
            }
        }
    }
}

void solve() {

    while (T--) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) { for (int j = 1; j <= n; j++) adj[i][j] = 0; }
        for (int i = 0; i < m; i++) {
            cin >> u[i] >> v[i]; adj[u[i]][v[i]] = adj[v[i]][u[i]] = 1;
        }
        int ans = 0;
        for (int i = 0; i < m; i++) {
            adj[u[i]][v[i]] = adj[v[i]][u[i]] = 0;
            for (int j = 1; j <= n; j++) vis[j] = 0;
            bfs();
            if (cnt < n) ans++;
            adj[u[i]][v[i]] = adj[v[i]][u[i]] = 1;
        }
        cout << ans << nl;
    }

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}