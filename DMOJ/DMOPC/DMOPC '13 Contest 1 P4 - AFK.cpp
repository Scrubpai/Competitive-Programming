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

int T, L, W, dis[51][51]; bool vis[51][51]; char grid[51][51];
int dir[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };

void bfs(int sr, int sc) {
    queue<pii> q; q.push({sr, sc}); dis[sr][sc] = 0; vis[sr][sc] = true;
    while (!q.empty()) {
        pii cur = q.front(); q.pop();
        for (int k = 0; k < 4; k++) {
            int nr = cur.first + dir[k][0], nc = cur.second + dir[k][1];
            if (!vis[nr][nc] && nr >= 1 && nr <= W && nc >= 1 && nc <= L && grid[nr][nc] != 'X') {
                vis[nr][nc] = true; dis[nr][nc] = dis[cur.first][cur.second] + 1; q.push({nr, nc});
            }
        }
    }
}

void solve() {

    cin >> T;
    while (T--) {
        cin >> L >> W; int sr, sc, er, ec; ms(dis, -1); ms(vis, 0);
        for (int i = 1; i <= W; i++) {
            for (int j = 1; j <= L; j++) {
                cin >> grid[i][j];
                if (grid[i][j] == 'C') {sr = i, sc = j; }
                if (grid[i][j] == 'W') {er = i, ec = j; }
            }
        }
        bfs(sr, sc);
        if (dis[er][ec] == -1 || dis[er][ec] >= 60) cout << "#notworth" << nl;
        else cout << dis[er][ec] << nl;
    }

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}