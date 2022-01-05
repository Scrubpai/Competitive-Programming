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

int n, m, adj[51][51]; bool vis[51]; pii edge[2501];

void bfs() {
    queue<int> q; q.push(1); vis[1] = true;
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (int i = 1; i <= 50; i++) {
            if (adj[cur][i] && !vis[i]) { vis[i] = true; q.push(i); }
        }
    }
}

void solve() {

    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int s, t; cin >> s >> t; adj[s][t] = 1;
        edge[i] = {s, t};
    }
    for (int i = 1; i <= m; i++) {
        adj[edge[i].first][edge[i].second] = 0; ms(vis, 0);
        bfs();
        if (vis[n]) cout << "YES" << nl;
        else cout << "NO" << nl;
        adj[edge[i].first][edge[i].second] = 1;
    }

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}