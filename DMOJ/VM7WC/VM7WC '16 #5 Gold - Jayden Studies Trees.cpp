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

//remember to remove ios stuff if i use scanf LOL

//printf("%05lld\n", x); --> print last 5 digits including 0's
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

const int MM = 1e4 + 5;
int N, dis[MM], st = 1, ans; vector<int> adj[MM];

void dfs(int cur, int pa) {
    for (int v : adj[cur]) {
        if (v != pa) {
            dis[v] = dis[cur] + 1;
            if (dis[v] > ans) { ans = dis[v]; st = v; }
            dfs(v, cur);
        }
    }
}

void solve() {

    cin >> N;
    for (int i = 1; i < N; i++) {
        int x, y; cin >> x >> y;
        adj[x].push_back(y); adj[y].push_back(x);
    }
    dfs(1, 0); ms(dis, 0); dfs(st, 0);
    cout << ans << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}