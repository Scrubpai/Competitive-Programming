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
int n, m, p[MM], vis[MM], mx, ans; vector<pii> adj[MM];

void dfs(int cur, int val, int weight) {
    vis[cur] = val;
    for (pii p : adj[cur]) {
        if (p.second < weight) continue;
        int v = p.first;
        if (!vis[v]) {
            dfs(v, val, weight);
        }
    }
}

bool check(int x) {
    ms(vis, 0); int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i, ++cnt, x);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (p[i] != i) {
            //cow i is at location p[i]
            if (vis[i] != vis[p[i]]) return 0;
        }
    }
    return 1;
}

void solve(int tc) {

    cin >> n >> m;
    bool flag = 1;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        if (p[i] != i) flag = 0;
    }
    if (flag) { cout << -1 << nl; return; }
    for (int i = 1, a, b, w; i <= m; i++) {
        cin >> a >> b >> w; mx = max(mx, w);
        adj[a].push_back({b, w}); adj[b].push_back({a, w});
    }
    int lo = 1, hi = mx;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (check(mid)) { ans = max(ans, mid); lo = mid + 1; }
        else hi = mid - 1;
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