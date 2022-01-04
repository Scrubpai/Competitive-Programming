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

struct E {
    int x, y, w;
};
bool cmp(E a, E b) {
    return a.w > b.w;
}

const int MM = 1e4 + 5;
int c, r, d, dsu[MM], dis[MM]; vector<E> edges; vector<pii> adj[MM];

int Find(int x) {
    if (dsu[x] == x) return x;
    else return dsu[x] = Find(dsu[x]);
}

void dfs(int cur, int pa) {
    for (pii p : adj[cur]) {
        int v = p.first, w = p.second;
        if (v != pa) {
            dis[v] = min(dis[cur], w);
            dfs(v, cur);
        }
    }
}

void solve(int tc) {

    cin >> c >> r >> d; ms(dis, INF);
    for (int i = 0; i < r; i++) {
        int x, y, w; cin >> x >> y >> w; edges.push_back({x, y, w});
    }
    for (int i = 1; i <= c; i++) dsu[i] = i;
    sort(edges.begin(), edges.end(), cmp);
    for (E e : edges) {
        int u = e.x, v = e.y, d = e.w, fu = Find(u), fv = Find(v);
        if (fu != fv) {
            dsu[fu] = fv;
            adj[u].push_back({v, d}); adj[v].push_back({u, d});
        }
    }
    dfs(1, 0); int ans = INF;
    for (int i = 1; i <= d; i++) {
        int x; cin >> x;
        ans = min(ans, dis[x]);
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