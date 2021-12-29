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

const int MM = 2e5 + 5;
int n, m, k, tmp[90], cnt[90], ans; bool bad[90][90]; vector<pii> adj[MM]; vector<int> id[MM], v;

void dfs(int d, int edges, vector<int> &vis) {
    if (d == k + 1 && edges == n) {
        ans++; return;
    }
    for (int i = 1; i <= d; i++) {
        bool flag = 1;
        int hsh = (d - 1) * k + (i - 1);
        for (int x : vis) {
            if (bad[hsh][x]) { flag = 0; break; }
        }
        if (bad[hsh][hsh]) flag = 0;
        if (flag) {
            vis.push_back(hsh);
            dfs(d + 1, edges + cnt[hsh], vis);
            vis.pop_back();
        }
    }
}

void solve() {

    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({w, v});
    }
    for (int i = 1; i <= n; i++) sort(adj[i].begin(), adj[i].end());
    for (int i = 1; i <= n; i++) {
        int sz = adj[i].size();
        for (int j = 0; j < sz; j++) {
            int node = adj[i][j].second, val = (sz - 1) * k + j;
            cnt[val]++; id[node].push_back(val);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (id[i].empty()) { cout << 0 << nl; return; }
        vector<int> nv; ms(tmp, 0);
        for (int x : id[i]) {
            if (tmp[x] <= 1) {
                tmp[x]++;
                nv.push_back(x);
            }
        }
        id[i] = nv;
        for (int x = 0; x < id[i].size(); x++) {
            for (int y = x + 1; y < id[i].size(); y++) {
                bad[ id[i][x] ][ id[i][y] ] = bad[ id[i][y] ][ id[i][x] ] = 1;
            }
        }
    }
    dfs(1, 0, v);
    cout << ans << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}