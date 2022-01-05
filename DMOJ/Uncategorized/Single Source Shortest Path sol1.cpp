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

int n, m, dis[1005]; priority_queue<pii, vector<pii>, greater<pii>> pq; vector<pii> adj[1005];

void solve(int tc) {

    cin >> n >> m; ms(dis, INF);
    for (int i = 1, u, v, w; i <= m; i++) {
        cin >> u >> v >> w;
        adj[u].push_back({w, v}); adj[v].push_back({w, u});
    }
    dis[1] = 0; pq.push({0, 1});
    while (!pq.empty()) {
        pii cur = pq.top(); pq.pop(); int u = cur.second, d = cur.first;
        if (dis[u] < d) continue;
        for (pii p : adj[u]) {
            if (dis[p.second] > dis[u] + p.first) {
                dis[p.second] = dis[u] + p.first;
                pq.push({dis[p.second], p.second});
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (dis[i] == INF) cout << -1 << nl;
        else cout << dis[i] << nl;
    }

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tc = 1; //cin >> tc;
    for (int t = 0; t < tc; t++) solve(t);

    return 0;
}