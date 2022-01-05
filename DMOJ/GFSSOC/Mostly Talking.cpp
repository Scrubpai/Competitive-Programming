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

const int MM = 5e5 + 5;
int n, m, d; ll dis1[MM], dis2[MM]; vector<pll> adj1[MM], adj2[MM];

void dijkstra(int st, vector<pll> adj[MM], ll dis[]) {
    dis[st] = 0; priority_queue<pll, vector<pll>, greater<pll>> pq; pq.push({0, st});
    while (!pq.empty()) {
        ll u = pq.top().second, d = pq.top().first; pq.pop();
        if (dis[u] < d) continue;
        for (pll p : adj[u]) {
            ll v = p.first; d = dis[u] + p.second;
            if (dis[v] > d) {
                dis[v] = d; pq.push({dis[v], v});
            }
        }
    }
}

void solve(int tc) {

    cin >> n >> m;
    for (int i = 1, a, b; i <= m; i++) {
        ll k; cin >> a >> b >> k;
        adj1[a].push_back({b, k}); adj2[b].push_back({a, k});
    }
    ms(dis1, LL_INF); ms(dis2, LL_INF);
    dijkstra(1, adj1, dis1); dijkstra(n, adj2, dis2); ll ans = dis1[n];
    cin >> d;
    for (int i = 1; i <= d; i++) {
        ll a, b, g; cin >> a >> b >> g;
        ans = min(ans, dis1[a] + g + dis2[b]);
    }
    if (ans > (1 << 30)) cout << -1 << nl;
    else cout << ans << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tc = 1; //cin >> tc;
    for (int t = 0; t < tc; t++) solve(t);

    return 0;
}