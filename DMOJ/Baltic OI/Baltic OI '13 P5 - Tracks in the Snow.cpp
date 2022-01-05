//why tle lol
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
#define ms(x, y) memset(x, y, sizeof(x))
#define nl '\n'
typedef unsigned long long ull;
const lld pi = 3.14159265358979323846;
const int MOD = 1e9 + 7;

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

int H, W, dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}}, ans; char grid[4005][4005]; bool vis[4005][4005];

void bfs(queue<pii>& q, queue<pii> &q2, char c) {
    while (!q.empty()) {
        int i = q.front().first, j = q.front().second; q.pop();
        for (int k = 0; k < 4; k++) {
            int nr = i + dir[k][0], nc = j + dir[k][1];
            if (nr < 1 || nc < 1 || nr > H || nc > W || grid[nr][nc] == '.' || vis[nr][nc]) continue;
            if (grid[nr][nc] != c) q2.push({nr, nc});
            else q.push({nr, nc});
            vis[nr][nc] = 1;
        }
    }
    if (!q2.empty()) {
        ans++;
        if (c == 'R') bfs(q2, q, 'F');
        else bfs(q2, q, 'R');
    }
}

void solve(int tc) {

    cin >> H >> W;
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            cin >> grid[i][j];
        }
    }
    queue<pii> q; queue<pii> q2; q.push({1, 1}); ans = 1; vis[1][1] = 1;
    bfs(q, q2, grid[1][1]);
    cout << ans << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);

    return 0;
}