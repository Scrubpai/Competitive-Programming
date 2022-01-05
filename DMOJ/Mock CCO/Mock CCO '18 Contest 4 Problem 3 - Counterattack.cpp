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
//coordinate compression:sort(val.begin(), val.end());
//		val.resize(unique(val.begin(), val.end()) - val.begin());
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

const int MM = 5e3 + 5;
int n, m, dis[MM], disrev[MM]; vector<pii> adj[MM];

void dijkstra(int st, int d[]) {
    priority_queue<pii, vector<pii>, greater<pii>> pq; d[st] = 0; pq.push({0, st});
    while (!pq.empty()) {
        int u = pq.top().second, w = pq.top().first; pq.pop();
        if (d[u] < w) continue;
        for (pii p : adj[u]) {
            int v = p.first; w = d[u] + p.second;
            if (d[v] > w) {
                d[v] = w; pq.push({d[v], v});
            }
        }
    }
}

void solve(int tc) {

    cin >> n >> m; ms(dis, INF); ms(disrev, INF);
    for (int i = 1, a, b, w; i <= m; i++) {
        cin >> a >> b >> w;
        adj[a].push_back({b, w}); adj[b].push_back({a, w});
    }
    dijkstra(1, dis); dijkstra(n, disrev);
    int ans = INF;
    for (int i = 1; i <= n; i++) {
        for (pii p : adj[i]) {
            int d = dis[i] + p.second + disrev[p.first];
            if (d > dis[n] && d < ans) ans = d;
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