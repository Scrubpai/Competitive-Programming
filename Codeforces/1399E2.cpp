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
int T, n; ll cnt[MM], S, w[MM], c1[(int)1e7 + 5], c2[(int)1e7 + 5]; vector<Q> adj[MM]; priority_queue<pll> pq; ll sum1, sum2, tot; vector<int> v[3];
int cur1, cur2;

ll getDiff(int i) {
    return w[i] * cnt[i] - (w[i] / 2) * cnt[i];
}

void dfs(int cur, int pa) {
    bool flag = 0;
    for (Q q : adj[cur]) {
        if (q.v != pa) {
            dfs(q.v, cur); flag = 1;
            cnt[cur] += cnt[q.v]; w[q.v] = q.w; v[q.c].push_back(q.v);
        }
    }
    if (!flag) cnt[cur] = 1;
}

void solve() {

    cin >> T;
    while (T--) {
        cin >> n >> S; while (!pq.empty()) pq.pop(); sum1 = 0; sum2 = 0; tot = 0; cur1 = 1; cur2 = 1; sum1 = 0;  sum2 = 0; v[1].clear(); v[2].clear();
        for (int i = 1; i <= n; i++) { adj[i].clear(); cnt[i] = 0; w[i] = cnt[i] = c1[i] = c2[i] = 0; }
        for (int i = 2; i <= n; i++) {
            int x, y, cost; ll weight; cin >> x >> y >> weight >> cost;
            adj[x].push_back({y, cost, weight}); adj[y].push_back({x, cost, weight});
        }
        dfs(1, 0);
        for (int x : v[1]) { pq.push({getDiff(x), x}); sum1 += w[x] * cnt[x]; tot += w[x] * cnt[x]; }
        c1[0] = 0;
        while (sum1 > 0) {
            pll p = pq.top(); pq.pop(); sum1 -= p.first;
            w[p.second] /= 2; c1[cur1] = p.first + c1[cur1 - 1]; cur1++;
            pq.push({getDiff(p.second), p.second});
        }
        while (!pq.empty()) pq.pop();
        for (int x : v[2]) { pq.push({getDiff(x), x}); sum2 += w[x] * cnt[x]; tot += w[x] * cnt[x]; }
        c2[0] = 0;
        while (sum2 > 0) {
            pll p = pq.top(); pq.pop(); sum2 -= p.first;
            w[p.second] /= 2; c2[cur2] = p.first + c2[cur2 - 1]; cur2++;
            pq.push({getDiff(p.second), p.second});
        }
        ll ans = LL_INF; c1[cur1] = LL_INF; c2[cur2] = LL_INF;
        for (int i = 0; i < cur1; i++) {
            ll need = max(1LL * 0, tot - c1[i] - S);
            int idx = lower_bound(c2, c2 + cur2, need) - c2;
            if (idx == cur2) continue;
            ans = min(ans, 1LL * i + 2 * 1LL * idx);
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