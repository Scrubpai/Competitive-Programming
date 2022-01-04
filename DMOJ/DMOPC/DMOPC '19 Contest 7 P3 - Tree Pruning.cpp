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
//#define sz(a) sizeof(a)/sizeof(a[0])
//#define AUT auto
#define f first
#define s second
#define nl '\n'
typedef unsigned long long ull;
const int MN = 1e6 + 5;
const int MOD = 1000000007;

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

ll n, k, w[MN]; vector<int> adj[MN]; bool vis[MN]; vector<int> ans; bool flag = false;

void dfs(int u, int par, ll val) {
    if (flag) return;
    if (val >= k && val <= 2 * k) {
        cout << ans.size() << nl;
        for (int v : ans) cout << v << " ";
        flag = true;
        return;
    }

    for (int v : adj[u]) {
        if (vis[v]) continue;
        if (v != par) {
            ans.push_back(v); dfs(v, u, w[v] + val); ans.erase(ans.begin() + ans.size() - 1);
        }
    }
}

void solve() {

    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
        if (w[i] >= k && w[i] <= 2 * k) { cout << 1 << nl << i << nl; return; }
        if (w[i] > 2 * k) vis[i] = true;
    }
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v; adj[u].push_back(v); adj[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        if (flag) return;
        ans.clear(); ans.push_back(i);
        dfs(i, 0, w[i]);
    }

    cout << -1 << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}