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

const int MM = 1e5 + 5;
ll n, p[MM], cnt[MM], val[MM], m; vector<int> adj[MM];

void dfs(int cur, int pa) {
    for (int v : adj[cur]) {
        if (v != pa) {
            dfs(v, cur);
            cnt[cur] += cnt[v];
        }
    }
    cnt[cur]++;
}

void solve(int tc) {

    cin >> n;
    for (int i = 1; i <= n; i++) adj[i].clear(), cnt[i] = 0;
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v); adj[v].push_back(u);
    }
    cin >> m;
    for (int i = 1; i <= m; i++) { cin >> p[i]; }
    sort(p + 1, p + 1 + m);
    while (m > n - 1) {
        p[m-1] = (p[m-1] * 1LL * p[m]) % MOD;
        m--;
    }
    reverse(p + 1, p + 1 + m);
    dfs(1, 0);
    for (int i = 2; i <= n; i++) {
        val[i] = 1LL * cnt[i] * (n - cnt[i]);
    }
    sort(val + 2, val + n + 1, greater<ll>());
    for (int i = 2; i <= n; i++) {
        while (val[i] >= MOD) val[i] %= MOD;
    }
    for (int i = 1; i <= m; i++) {
        while (p[i] >= MOD) p[i] %= MOD;
    }
    ll ans = 0;
    for (int i = 2; i <= n; i++) {
        ll mult = 0;
        if (i - 1 > m) mult = 1LL;
        else mult = p[i-1] % MOD;
        ans = (ans % MOD + (mult * 1LL * val[i]) % MOD) % MOD;
    }

    cout << ans << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tc = 1; cin >> tc;
    for (int t = 0; t < tc; t++) solve(t);

    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
 * // Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
*/