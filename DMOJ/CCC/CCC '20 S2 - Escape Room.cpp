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
//#define sz(a) sizeof(a)/sizeof(a[0])
//#define AUT auto
#define f first
#define s second
#define nl '\n'
typedef unsigned long long ull;
const int MN = 2e5 + 5;
const int MOD = 1e9 + 7;

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

int M, N; int a[1001][1001]; vector<pii> adj[1000001]; bool vis[1001][1001];

void solve() {

    cin >> M >> N;
    for (int i=1; i<=M; i++) {
        for (int j=1; j<=N; j++) {
            cin >> a[i][j];
            adj[a[i][j]].push_back({i, j});
        }
    }
    queue<pii> q; q.push({M, N}); vis[M][N] = true;
    while (!q.empty()) {
        pii cur = q.front(); q.pop();
        int x = cur.f, y = cur.s, val = x*y;
        for (pii p : adj[val]) {
            if (!vis[p.f][p.s]) {
                vis[p.f][p.s] = true;
                q.push({p.f, p.s});
            }
        }
    }
    if (vis[1][1]) cout << "yes" << nl;
    else cout << "no" << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}