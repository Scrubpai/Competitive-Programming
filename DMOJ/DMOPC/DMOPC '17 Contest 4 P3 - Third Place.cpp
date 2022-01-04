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
int n, root, nod; vector<pii> adj[MM]; ll dis[MM], maxd, ans;

void dfs(int cur, int pa, ll d) {
    dis[cur] = d;
    if (d > maxd) {
        maxd = d; root = cur;
    }
    for (pii p : adj[cur]) {
        if (p.first != pa) {
            dfs(p.first, cur, d + p.second);
        }
    }
}

void solve(int tc) {

    cin >> n;
    for (int i = 1; i < n; i++) {
        int a, b, c; cin >> a >> b >> c;
        adj[a].push_back({b, c}); adj[b].push_back({a, c});
    }
    dfs(1, 0, 0); maxd = 0; nod = root; dfs(root, 0, 0); maxd = 0;
    for (int i = 1; i <= n; i++) {
        if (dis[i] >= maxd) ans = maxd, maxd = dis[i];
        else if (dis[i] > ans) ans = dis[i];
    }
    dfs(root, 0, 0);
    for (int i = 1; i <= n; i++) {
        if (i == nod) continue;
        if (dis[i] >= maxd) ans = maxd, maxd = dis[i];
        else if (dis[i] > ans) ans = dis[i];
    }
    cout << ans << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tc = 1;// cin >> tc;
    for (int t = 0; t < tc; t++) solve(t);

    return 0;
}