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

int T = 5, n, dis[101]; vector<int> adj[105]; int vis[101]; int loop;

void dfs(int cur, int par) {
    vis[cur] = 1; dis[cur] = dis[par] + 1;
    for (int v : adj[cur]) {
        if (vis[v] == 1) { loop = max(loop, dis[cur] - dis[v] + 1); return;  }
        else if (vis[v] == 0) dfs(v, cur);
    }
    vis[cur] = 2;
}

void solve() {

    while (T--) {
        cin >> n; ms(vis, 0); ms(dis, 0); loop = 0;
        for (int i = 1; i <= 100; i++) adj[i].clear();
        for (int i = 1, x, y; i <= n; i++) {
            cin >> x >> y; adj[x].push_back(y);
        }
        dfs(1, 0);
        cout << loop << nl;
    }

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}