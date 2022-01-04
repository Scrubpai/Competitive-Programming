#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<string> vs;
typedef complex<double> pnt;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define rep1(i, a, n) for (int i=a; i<=n; i++)
#define per(i,a,n) for (int i=a-1;i>=n;i--)
#define per1(i,a,n) for (int i=a;i>=n;i--)
#define endl '\n'
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
#define f first
#define s second
#define nl '\n'
typedef unsigned long long ull;
const int MN = 200005;
const int MOD = 998244353;

ll gcd(ll a, ll b){return b == 0 ? a : gcd(b, a % b);}
ll lcm(ll a, ll b){return a*b/gcd(a,b);}
ll pwmd(ll b, ll exp) {
    ll ret = 1;
    while (exp>0) {
        if (exp%2==1) ret = (ret*b)%MOD;
        exp/=2;
        b = (b*b)%MOD;
    }
    return ret;
}

int K, N; vector<pii> adj[MN]; ll ppl[MN]; ll sz[MN]; ll ans; bool vis[MN]; ll dis[MN];

void dfs(int u, int pa) {
    sz[u] = ppl[u];
    for (pii p : adj[u]) {
        if (p.f!=pa) {
            dfs(p.f, u);
            sz[u]+=sz[p.f];
        }
    }
}

int getCenter(int u, int pa, int tot) {
    for (pii p : adj[u]) {
        if (pa!=p.f && sz[p.f]*2>tot) {
            return getCenter(p.f, u, tot);
        }
    }
    return u;
}

void bfs(int start) {
    queue<int> q; vis[start] = true; q.push(start); dis[start] = 0;
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (pii p : adj[cur]) {
            if (!vis[p.f]) {
                dis[p.f] = dis[cur] + p.s; ans = (ans+(ppl[p.f]*dis[p.f]));
                vis[p.f] = true; q.push(p.f);
            }
        }
    }
}

void solve() {

    cin >> K >> N;
    rep1(i, 1, K) { int x; cin >> x; ppl[x]++; }
    rep(i, 1, N) {
        int u, v, d; cin >> u >> v >> d; adj[u].pb({v, d}); adj[v].pb({u, d});
    }
    dfs(1, 0);
    int node = getCenter(1, 0, sz[1]);
    bfs(node);
    cout << ans << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}