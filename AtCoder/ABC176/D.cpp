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
//coordinate compression:sort(val.begin(), val.end());
//		val.resize(unique(val.begin(), val.end()) - val.begin());
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

struct E {
    int d, r, c;
    bool operator < (const E &other) const {
        return this-> d > other.d;
    }
};

const int MM = 1e3 + 5;
int h, w, ch, cw, dh, dw, dis[MM][MM], dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}}; char grid[MM][MM]; bool vis[MM][MM];

void solve(int tc) {

    cin >> h >> w >> ch >> cw >> dh >> dw;
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            cin >> grid[i][j];
        }
    }
    priority_queue<E> pq; ms(dis, INF); dis[ch][cw] = 0; pq.push({0, ch, cw});
    while (!pq.empty()) {
        int r = pq.top().r, c = pq.top().c, d = pq.top().d; pq.pop();
        if (r < 1 || r > h || c < 1 || c > w || grid[r][c] == '#') continue;
        if (vis[r][c]) continue;
        vis[r][c] = 1; dis[r][c] = d;
        for (int k = 0; k < 4; k++) {
            int nr = r + dir[k][0], nc = c + dir[k][1];
            if (vis[nr][nc]) continue;
            pq.push({dis[r][c], nr, nc});
        }
        for (int i = r - 2; i <= r + 2; i++) {
            for (int j = c - 2; j <= c + 2; j++) {
                pq.push({dis[r][c] + 1, i, j});
            }
        }
    }
    if (dis[dh][dw] == INF) cout << -1 << nl;
    else cout << dis[dh][dw] << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tc = 1; //cin >> tc;
    for (int t = 0; t < tc; t++) solve(t);

    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
*/