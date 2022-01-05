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

int m, n; unordered_map<int, char> mp; vector<int> adj[30]; bool vis[30]; int dis[30], pre[30];

void bfs(int start) {
    dis[start] = 0; queue<int> q; vis[start] = 1; q.push(start); pre[start] = -1;
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (int v : adj[cur]) {
            if (!vis[v]) {
                vis[v] = true; q.push(v); dis[v] = dis[cur] + 1; pre[v] = cur;
            }
        }
    }
}

void solve() {

    cin >> m >> n;
    for (int i = 0; i < m; i++) {
        string a, b; cin >> a >> b;
        int u = a[0] - 'A', v = b[0] - 'A';
        mp[u] = a[0]; mp[v] = b[0];
        adj[u].push_back(v); adj[v].push_back(u);
    }
    for (int i = 0; i < n; i++) {
        string a, b; cin >> a >> b; ms(vis, 0);
        int u = a[0] - 'A', v = b[0] - 'A';
        bfs(u); string ans = "";
        for (int j = v; j != -1; j = pre[j]) {
            ans += mp[j];
        }
        for (int j = ans.size() - 1; j >= 0; j--) cout << ans[j];
        cout << nl;
    }

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}