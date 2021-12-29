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

struct Q {
    int v, c; ll w;
};

const int MM = 1e5 + 5;
int T, n; ll cnt[MM], S, w[MM], c[MM]; vector<pll> adj[MM]; priority_queue<pll> pq;

ll getDiff(int i) {
    return w[i] * cnt[i] - (w[i] / 2) * cnt[i];
}

void dfs(int cur, int pa) {
    bool flag = 0;
    for (pll p : adj[cur]) {
        ll v = p.first, weight = p.second;
        if (v != pa) {
            dfs(v, cur); flag = 1;
            cnt[cur] += cnt[v]; w[v] = weight; //c[q.v] = q.c;
        }
    }
    if (!flag) cnt[cur] = 1;
}

void solve() {

    cin >> T;
    while (T--) {
        cin >> n >> S; while (!pq.empty()) pq.pop();
        for (int i = 1; i <= n; i++) { adj[i].clear(); cnt[i] = 0; }
        for (int i = 2; i <= n; i++) {
            ll u, v, cost, weight; cin >> u >> v >> weight; // >> cost;
            adj[u].push_back({v, weight}); adj[v].push_back({u, weight});
        }
        dfs(1, 0); ll sum = 0; int ans = 0;
        for (ll i = 2; i <= n; i++) { pq.push({getDiff(i), i}); sum += w[i] * cnt[i]; }
        while (sum > S) {
            pll p = pq.top(); pq.pop();
            w[p.second] /= 2; sum -= p.first;
            pq.push({getDiff(p.second), p.second}); ans++;
        }
        cout << ans << nl;
    }

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}