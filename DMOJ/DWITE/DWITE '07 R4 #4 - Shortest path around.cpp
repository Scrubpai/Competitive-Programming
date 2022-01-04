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

int r = 10, c = 10, dis[15][15], dir[8][2] = { {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1} }; char a[15][15]; bool vis[15][15];

void solve(int tc) {

    int sr = -1, sc = -1, er, ec; ms(vis, 0); ms(dis, 0);
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            cin >> a[i][j];
            if (a[i][j] == 'X' && sr == -1) sr = i, sc = j;
            else if (a[i][j] == 'X') er = i, ec = j;
        }
    }
    queue<pii> q; vis[sr][sc] = 1; q.push({sr, sc});
    while (!q.empty()) {
        pii p = q.front(); q.pop();
        for (int k = 0; k < 8; k++) {
            int nr = p.first + dir[k][0], nc = p.second + dir[k][1];
            if (nr >= 1 && nr <= r && nc >= 1 && nc <= c && !vis[nr][nc] && a[nr][nc] != '#') {
                vis[nr][nc] = 1; dis[nr][nc] = dis[p.first][p.second] + 1; q.push({nr, nc});
            }
        }
    }
    cout << dis[er][ec] << nl;
    string lol; cin >> lol;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tc = 5;// cin >> tc;
    for (int t = 0; t < tc; t++) solve(t);

    return 0;
}