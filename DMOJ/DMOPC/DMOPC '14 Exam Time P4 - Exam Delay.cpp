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

struct E {
    int v; double t;
    bool operator < (const E &other) const {
        return this->t > other.t;
    }
};

int v, e, m, n, d, s, cnt[1005]; double dis[1005]; priority_queue<E> pq; vector<pair<int, double>> adj[1005];

void solve(int tc) {

    cin >> v >> e; ms(cnt, INF);
    for (int i = 1; i <= v; i++) dis[i] = INF;
    for (int i = 1; i <= e; i++) {
        cin >> m >> n >> d >> s; double t = ((double)d / s) * 60;
        adj[m].push_back({n,  t}); adj[n].push_back({m, t});
    }
    pq.push({1, 0}); dis[1] = 0; cnt[1] = 0;
    while (!pq.empty()) {
        E cur = pq.top(); pq.pop();
        if (dis[cur.v] < cur.t) continue;
        for (pair<int, double> p : adj[cur.v]) {
            double w = dis[cur.v] + p.second; int u = p.first;
            if (dis[u] >= w) {
                if ((dis[u] == w && cnt[cur.v] + 1 < cnt[u]) || (dis[u] > w)) {
                    cnt[u] = cnt[cur.v] + 1; dis[u] = w; pq.push({u, dis[u]});
                }
            }
        }
    }
    cout << cnt[v] << nl;
    cout << round(dis[v] / 0.75 - dis[v]) << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tc = 1; //cin >> tc;
    for (int t = 0; t < tc; t++) solve(t);

    return 0;
}