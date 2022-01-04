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

int n, t, k, d, dis[5001]; bool vis[5001]; vector<pii> adj[5001]; pii p[5001]; priority_queue<pii, vector<pii>, greater<pii>> pq;

void solve(int tc) {

    cin >> n >> t; ms(dis, INF);
    for (int i = 1, x, y, c; i <= t; i++) {
        cin >> x >> y >> c;
        adj[x].push_back({y, c}); adj[y].push_back({x, c});
    }
    cin >> k;
    for (int i = 1, z, pz; i <= k; i++) {
        cin >> z >> pz; p[i] = {z, pz};
    }
    cin >> d; pq.push({0, d}); dis[d] = 0;
    while (!pq.empty()) {
        int cur = pq.top().second; pq.pop();
        if (vis[cur]) continue;
        vis[cur] = 1;
        for (pii p : adj[cur]) {
            int v = p.first, w = p.second;
            if (vis[v]) continue;
            if (dis[v] > dis[cur] + w) {
                dis[v] = dis[cur] + w; pq.push({dis[v], v});
            }
        }
    }
    int ans = INF;
    for (int i = 1; i <= k; i++) {
        ans = min(ans, dis[p[i].first] + p[i].second);
    }
    cout << ans << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tc = 1; //cin >> tc;
    for (int t = 0; t < tc; t++) solve(t);

    return 0;
}