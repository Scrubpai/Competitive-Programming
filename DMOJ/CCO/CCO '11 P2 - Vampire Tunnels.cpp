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
#define ms(x, y) memset(x, y, sizeof(x))
#define nl '\n'
typedef unsigned long long ull;
const lld pi = 3.14159265358979323846;
const ll MOD = 1e9 + 7;

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

struct E {
    int v, d, u;
    bool operator < (const E &other) const {
        return this->d > other.d;
    }
};

//dis[i][j]: minimum time to get to point i, exposed to j sunlight
int n, e, s, dis[2000][4000]; vector<E> adj[2000]; priority_queue<E> pq;

void solve(int tc) {

    cin >> s >> n >> e; ms(dis, INF);
    for (int i = 1; i <= e; i++) {
        int a, b, c, d; cin >> a >> b >> c >> d; a++; b++;
        adj[a].push_back({b, c, d}); adj[b].push_back({a, c, d});
    }
    dis[1][0] = 0; pq.push({1, 0, 0});
    while (!pq.empty()) {
        E cur = pq.top(); pq.pop();
        if (dis[cur.v][cur.u] < cur.d) continue;
        for (E nxt : adj[cur.v]) {
            if (cur.u + nxt.u * nxt.d > s) continue;
            if (dis[nxt.v][cur.u + nxt.u * nxt.d] > dis[cur.v][cur.u] + nxt.d) {
                dis[nxt.v][cur.u + nxt.u * nxt.d] = dis[cur.v][cur.u] + nxt.d;
                pq.push({nxt.v, dis[nxt.v][cur.u + nxt.u * nxt.d], cur.u + nxt.u * nxt.d});
            }
        }
    }
    int ans = INF;
    for (int i = s; i >= 0; i--) {
        ans = min(ans, dis[n][i]);
    }
    if (ans == INF) cout << -1 << nl;
    else cout << ans << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tc = 1; //cin >> tc;
    for (int t = 0; t < tc; t++) solve(t);

    return 0;
}