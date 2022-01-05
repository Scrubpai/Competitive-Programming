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

const int MM = 1e6 + 5;
ll n, y[MM]; int maxd, root; bool vis[MM], ok[MM]; vector<int> adj[MM];

void dfs(int cur, int pa, int d) {
    if (d > maxd) {
        maxd = d; root = cur;
    }
    vis[cur] = 1;
    for (int v : adj[cur]) {
        if (v != pa) {
            dfs(v, cur, d + 1);
        }
    }
}

void solve(int tc) {

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> y[i];
        ll x = sqrt(y[i]);
        if (1LL * x * x + x == y[i]) {
            ok[i] = 1;
        }
    }
    for (int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        if (ok[a] && ok[b]) adj[a].push_back(b), adj[b].push_back(a);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (!vis[i] && ok[i]) {
            maxd = 0; dfs(i, 0, 1); maxd = 0; dfs(root, 0, 1); ans = max(ans, maxd);
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