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
int n, m, minx, maxx, miny, maxy, ans = INF; pii pos[MM]; vector<int> adj[MM]; bool vis[MM];

void dfs(int cur, int pa) {
    vis[cur] = 1;
    for (int v : adj[cur]) {
        if (!vis[v]) {
            dfs(v, cur);
        }
    }
    minx = min(minx, pos[cur].first); maxx = max(maxx, pos[cur].first);
    miny = min(miny, pos[cur].second); maxy = max(maxy, pos[cur].second);
}

void solve(int tc) {

    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> pos[i].first >> pos[i].second;
    for (int i = 1, a, b; i <= m; i++) {
        cin >> a >> b;
        adj[a].push_back(b); adj[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            maxx = maxy = 0; minx = miny = INF;
            dfs(i, 0);
            ans = min(ans, 2 * ((maxx - minx) + (maxy - miny)));
        }
    }
    cout << ans << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tc = 1; //cin >> tc;
    for (int t = 0; t < tc; t++) solve(t);

    return 0;
}