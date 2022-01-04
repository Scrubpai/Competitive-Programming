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
//#define sz(a) sizeof(a)/sizeof(a[0])
//#define AUT auto
//#define f first
//#define s second
#define nl '\n'
typedef unsigned long long ull;
const int MOD = 10;

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

const int MM = 1000005;
int N, M; vector<int> adj[MM]; int p, q; bool vis[MM];

bool bfs(int u, int v) {
    queue<int> q; q.push(u); vis[u] = true;
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (int v : adj[cur]) {
            if (!vis[v]) { vis[v] = true; q.push(v); }
        }
    }
    return vis[v];
}

void solve() {

    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
    }
    cin >> p >> q;
    if (bfs(p, q)) cout << "yes" << nl;
    else {
        ms(vis, 0);
        if (bfs(q, p)) cout << "no" << nl;
        else cout << "unknown" << nl;
    }

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}