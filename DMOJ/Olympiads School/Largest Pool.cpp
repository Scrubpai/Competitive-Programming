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
const int MN = (int)1e5 + 5;
const ll MOD = 998244353;

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

bool vis[101][101]; bool grid[101][101];
int dir[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

int N, M;

int bfs(int sx, int sy) {
    queue<pii> q; vis[sx][sy] = true; q.push({sx, sy}); int mx = 1;
    while (!q.empty()) {
        pii cur = q.front(); q.pop();
        int r = cur.f; int c = cur.s;
        for (int k=0; k<4; k++) {
            int nr = r + dir[k][0]; int nc = c + dir[k][1];
            if (nr>N || nr<1) continue;
            if (nc>M || nc<1) continue;
            if (grid[nr][nc] && !vis[nr][nc]) {
                q.push({nr, nc}); vis[nr][nc] = true; mx++;
            }
        }
    }
    return mx;
}

void solve() {

    int K; cin >> N >> M >> K;
    rep(i, 0, K) {
        int x; int y; cin >> x >> y;
        grid[x][y] = true;
    }

    int ans = 0;
    rep1(i, 1, N) {
        rep1(j, 1, M) {
            if (!vis[i][j] && grid[i][j]) {
                ans = max(ans, bfs(i, j));
            }
        }
    }

    cout << ans << nl;

}

int32_t main() {
   // ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}