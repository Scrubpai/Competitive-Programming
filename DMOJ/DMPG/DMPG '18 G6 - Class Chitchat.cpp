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

const int MM = 1e5 + 5;
ll n, c, K, dis[MM], v[MM]; vector<int> classes[MM]; vector<int> adj[MM]; priority_queue<pll, vector<pll>, greater<pll>> pq;

void solve(int tc) {

    cin >> n >> c >> K;
    for (int i = 1; i <= n; i++) { cin >> v[i];  dis[i] = LL_INF; }
    dis[1] = 0;
    for (int i = 1; i <= n; i++) {
        int num; cin >> num;
        for (int j = 1, x; j <= num; j++) {
            cin >> x; classes[i].push_back(x);
            adj[x].push_back(i);
        }
    }
    pq.push({0, 1});
    while (!pq.empty()) {
        ll u = pq.top().second, x = pq.top().first; pq.pop();
        if (dis[u] < x) continue;
        for (int cla : classes[u]) {
            for (int nxt : adj[cla]) {
                if (nxt == u) continue;
                ll val = abs(v[nxt] - v[u]) + K;
                if (dis[nxt] > dis[u] + val) {
                    dis[nxt] = dis[u] + val; pq.push({dis[nxt], nxt});
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (dis[i] == LL_INF) cout << -1 << nl;
        else cout << dis[i] << nl;
    }

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tc = 1; //cin >> tc;
    for (int t = 0; t < tc; t++) solve(t);

    return 0;
}