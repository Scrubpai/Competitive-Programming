#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<string> vs;
typedef complex<double> pnt;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
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
#define f first
#define s second
#define nl '\n'
typedef unsigned long long ull;
const int MN = (int)1e6 + 5;
const int MOD = (int)1e9 + 7;

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

struct E {
    int v; int h;
    bool operator < (const E &other) const {
        return this-> h > other.h;
    }
};

int N, M, T; vector<E> adj[301]; int dis[301][301]; int val[301][301];

int dijkstra(int start, int end) {
    priority_queue<E> pq; dis[start][start] = 0; val[start][start] = 0; pq.push({start, 0});
    while (!pq.empty()) {
        E cur = pq.top(); pq.pop(); int h = cur.h; int v = cur.v;
        for (E e : adj[v]) {
            if (val[start][e.v] > max(val[start][v], e.h)) {
                val[start][e.v] = max(val[start][v], e.h);
                pq.push({e.v, val[start][e.v]});
            }
        }
    }
    return val[start][end];
}

void solve() {

    cin >> N >> M >> T; ms(dis, INF); ms(val, INF);
    rep(i, 0, M) {
        int S, e, h; cin >> S >> e >> h;
        adj[S].pb({e, h});
    }
    rep(i, 0, T) {
        int A; int B; cin >> A >> B;
        int ans = dijkstra(A, B);
        if (ans==INF) cout << -1 << nl;
        else cout << ans << nl;
    }

}

int32_t main() {
   // ios_base::sync_with_stdio(false);
   // cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}