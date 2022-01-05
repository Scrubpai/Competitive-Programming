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

const int MM = 1e4 + 5;
int n, C, K, sz[MM], cherries[MM], ans; vector<pii> adj[MM];

void dfs(int cur, int cost, int pa) {
    sz[cur] = cost;
    for (pii p : adj[cur]) {
        int v = p.first, w = p.second;
        if (v != pa) {
            dfs(v, w, cur);
            sz[cur] += sz[v]; cherries[cur] += cherries[v];
        }
    }
    if (sz[cur] <= K && cherries[cur] >= C) ans++;
}

void solve(int tc) {

    cin >> n >> C >> K;
    for (int i = 1; i <= n; i++) cin >> cherries[i];
    for (int i = 1, a, b, k; i < n; i++) {
        cin >> a >> b >> k;
        adj[a].push_back({b, k}); adj[b].push_back({a, k});
    }
    dfs(1, 1e9, 0);
    cout << ans << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tc = 1;// cin >> tc;
    for (int t = 0; t < tc; t++) solve(t);

    return 0;
}