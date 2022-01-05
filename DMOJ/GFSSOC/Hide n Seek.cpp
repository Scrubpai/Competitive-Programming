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

int n, m, t, dir[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} }, dis[10][25][25], ord[6] = {1, 2, 3, 4, 5}; char a[25][25]; pii pos[10];

void bfs(int x) {
    int sr = pos[x].first, sc = pos[x].second; queue<pii> q; dis[x][sr][sc] = 0; q.push({sr, sc});
    while (!q.empty()) {
        pii cur = q.front(); q.pop();
        for (int k = 0; k < 4; k++) {
            int nr = cur.first + dir[k][0], nc = cur.second + dir[k][1];
            if (nr >= 1 && nr <= n && nc >= 1 && nc <= m && a[nr][nc] != 'X' && dis[x][nr][nc] == -1) {
                dis[x][nr][nc] = dis[x][cur.first][cur.second] + 1; q.push({nr, nc});            }
        }
    }
}

void solve(int tc) {

    cin >> n >> m >> t; int tmp = 1; ms(dis, -1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            if (a[i][j] == 'G') pos[0] = {i, j};
            else if (a[i][j] == 'H') pos[tmp++] = {i, j};
        }
    }
    for (int i = 0; i <= t; i++) { bfs(i); }
    int ans = INF;
    do {
        int r = pos[ord[0]].first, c = pos[ord[0]].second, val = dis[0][r][c];
        for (int i = 1; i < t; i++) {
            r = pos[ord[i]].first, c = pos[ord[i]].second;
            val += dis[ord[i-1]][r][c];
        }
        ans = min(ans, val);
    } while (next_permutation(ord, ord + t));
    cout << ans << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tc = 1;// cin >> tc;
    for (int t = 0; t < tc; t++) solve(t);

    return 0;
}