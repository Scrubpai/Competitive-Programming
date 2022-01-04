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

int n, m, dis[105][105], sr, sc, dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}}; char grid[105][105]; vector<pii> cams, emp;
priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> pq;

void solve(int tc) {

    cin >> n >> m; ms(dis, INF);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'S') sr = i, sc = j;
            else if (grid[i][j] == '.') emp.push_back({i, j});
            else if (grid[i][j] == 'C') cams.push_back({i, j});
        }
    }
    for (pii x : cams) {
        int r = x.first, c = x.second;
        for (int i = c; i <= m; i++) {
            if (grid[r][i] == 'W') break;
            if (grid[r][i] == '.' || grid[r][i] == 'C' || grid[r][i] == 'S') grid[r][i] = 'X';
        }
        for (int i = c; i >= 1; i--) {
            if (grid[r][i] == 'W') break;
            if (grid[r][i] == '.' || grid[r][i] == 'C' || grid[r][i] == 'S') grid[r][i] = 'X';
        }
        for (int i = r; i <= n; i++) {
            if (grid[i][c] == 'W') break;
            if (grid[i][c] == '.' || grid[i][c] == 'C' || grid[i][c] == 'S') grid[i][c] = 'X';
        }
        for (int i = r; i >= 1; i--) {
            if (grid[i][c] == 'W') break;
            if (grid[i][c] == '.' || grid[i][c] == 'C' || grid[i][c] == 'S') grid[i][c] = 'X';
        }
    }
    pq.push({0, {sr, sc}});
    while (!pq.empty()) {
        pair<int, pii> cur = pq.top(); pq.pop();
        int cr = cur.second.first, cc = cur.second.second, d = cur.first;
        if (cr < 1 || cr > n || cc < 1 || cc > m || grid[cr][cc] == 'W' || grid[cr][cc] == 'X') continue;
        if (dis[cr][cc] <= d) continue;
        dis[cr][cc] = d;
        if (grid[cr][cc] == 'U') {
            pq.push({dis[cr][cc], {cr-1, cc}});
        } else if (grid[cr][cc] == 'R') {
            pq.push({dis[cr][cc], {cr, cc+1}});
        } else if (grid[cr][cc] == 'D') {
            pq.push({dis[cr][cc], {cr+1, cc}});
        } else if (grid[cr][cc] == 'L') {
            pq.push({dis[cr][cc], {cr, cc-1}});
        } else {
            for (int k = 0; k < 4; k++) {
                int nr = cr + dir[k][0], nc = cc + dir[k][1];
                pq.push({d + 1, {nr, nc}});
            }
        }
    }
    for (pii x : emp) {
        int r = x.first, c = x.second;
        if (dis[r][c] == INF) cout << -1 << nl;
        else cout << dis[r][c] << nl;
    }

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tc = 1;// cin >> tc;
    for (int t = 0; t < tc; t++) solve(t);

    return 0;
}