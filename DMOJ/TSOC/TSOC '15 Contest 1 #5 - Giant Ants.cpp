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

int N, M, W; double dis[101], disants[101]; bool vis[101]; vector<int> adj[101]; queue<int> q;

void solve() {

    cin >> N >> M;
    for (int i = 1; i <= M; i++) {
        int u, v; cin >> u >> v; adj[u].push_back(v); adj[v].push_back(u);
    }
    cin >> W; ms(disants, INF); ms(dis, INF);
    for (int i = 1; i <= W; i++) {
        int x; cin >> x; q.push(x); vis[x] = true; disants[x] = 0;
    }
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (int v : adj[cur]) {
            if (!vis[v]) {
                vis[v] = true; q.push(v); disants[v] = disants[cur] + 4;
            }
        }
    }
    ms(vis, 0);
    vis[1] = true; dis[1] = 0; q.push(1);
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (int v : adj[cur]) {
            if (!vis[v] && dis[cur] + 1 < disants[v]) {
                vis[v] = true; q.push(v); dis[v] = dis[cur] + 1;
            }
        }
    }
    if (vis[N]) cout << dis[N] << nl;
    else cout << "sacrifice bobhob314" << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}