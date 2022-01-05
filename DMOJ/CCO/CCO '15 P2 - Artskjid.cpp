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
#define nl '\n'
typedef unsigned long long ull;
const int MOD = 1000000000;
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

int n, m, adj[19][19], dp[19][1 << 19];

int dfs(int cur, int mask) {
    if (cur == n - 1) return 0;
    if (dp[cur][mask] != -1) return dp[cur][mask];
    int ans = -INF;
    for (int i = 0; i < n; i++) {
        if (adj[cur][i] && !(mask & (1 << i))) {
            int new_mask = mask | (1 << i);
            ans = max(ans, dfs(i, new_mask) + adj[cur][i]);
        }
    }
    return dp[cur][mask] = ans;
}

void solve() {

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y, d; cin >> x >> y >> d;
        adj[x][y] = d;
    }
    ms(dp, -1);
    cout << dfs(0, 1) << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}