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

const int MM = 2e4 + 5;
int n, m, dis1[MM], dis2[MM]; vector<pii> adj1[MM], adj2[MM];

void dijkstra(int st, vector<pii> adj[MM], int dis[]) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dis[st] = 0; pq.push({0, st});
    while (!pq.empty()) {
        int cur = pq.top().second, d = pq.top().first; pq.pop();
        if (dis[cur] < d) continue;
        for (pii p : adj[cur]) {
            int v = p.first; d = dis[cur] + p.second;
            if (dis[v] > d) {
                dis[v] = d; pq.push({dis[v], v});
            }
        }
    }
}

void solve(int tc) {

    cin >> n >> m; ms(dis1, INF); ms(dis2, INF); int ans = INF;
    for (int i = 1, a, b, l; i <= m; i++) {
        cin >> a >> b >> l;
        adj1[a].push_back({b, l}); adj2[b].push_back({a, l});
    }
    dijkstra(1, adj1, dis1); dijkstra(n, adj2, dis2);
    if (dis1[n] == INF) { cout << -1 << nl; return; }
    for (int i = 1; i <= n; i++) {
        for (pii p : adj1[i]) {
            int v = p.first, d = p.second;
            if (dis1[i] + dis2[v] + d != dis1[n] && dis1[i] + dis2[v] + d < ans) ans = dis1[i] + dis2[v] + d;
        }
    }
    if (ans == INF) cout << -1 << nl;
    else cout << ans << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tc = 1; //cin >> tc;
    for (int t = 0; t < tc; t++) solve(t);

    return 0;
}