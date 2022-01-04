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

int r, c, t, dis[1005][1005]; char grid[1005][1005]; int sr, sc, er, ec, tr, tc; queue<pii> q; bool vis[1005][1005];
int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

void solve() {

    cin >> r >> c >> sr >> sc >> er >> ec; sr++; sc++; er++; ec++; ms(dis, INF); dis[sr][sc] = 0;
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            cin >> grid[i][j];
        }
    }
    q.push({sr, sc}); vis[sr][sc] = 1;
    while (!q.empty()) {
        pii p = q.front(); q.pop();
        int cr = p.first, cc = p.second;
        for (int k = 0; k < 4; k++) {
            int nr = cr + dir[k][0], nc = cc + dir[k][1];
            if (nr >= 1 && nr <= r && nc >= 1 && nc <= c && grid[nr][nc] != 'X' && !vis[nr][nc]) {
                vis[nr][nc] = 1; q.push({nr, nc}); dis[nr][nc] = dis[cr][cc] + 1;
            }
        }
    }
    cin >> t; int ans = 0;
    while (t--) {
        cin >> tr >> tc; tr++; tc++;
        ans = max(ans, dis[er][ec] - dis[tr][tc]);
    }
    cout << ans << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}