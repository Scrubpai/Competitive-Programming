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

int T = 5, dis[11][11]; bool vis[11][11]; char grid[11][11]; int ans; string lol; queue<pii> q;
int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

void bfs() {
    while (!q.empty()) {
        pii p = q.front(); q.pop();
        int cr = p.first, cc = p.second;
        for (int k = 0; k < 4; k++) {
            int nr = cr + dir[k][0], nc = cc + dir[k][1];
            if (nr >= 0 && nr < 10 && nc >= 0 && nc < 10 && !vis[nr][nc]) {
                vis[nr][nc] = 1; q.push({nr, nc}); dis[nr][nc] = min(dis[nr][nc], dis[cr][cc] + 1);
            }
        }
    }
}

void solve() {

    while (T--) {
        ms(vis, 0); ms(dis, INF); ans = 0;
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                cin >> grid[i][j];
                if (grid[i][j] == '.') { dis[i][j] = 0; vis[i][j] = 1; }
                else if (grid[i][j] == 'F') { dis[i][j] = 0; q.push({i, j}); vis[i][j] = 1; }
            }
        }
        bfs();
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                ans = max(ans, dis[i][j]);
            }
        }
        if (ans == INF) cout << -1 << nl;
        else cout << ans << nl;
        cin >> lol;
    }

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}