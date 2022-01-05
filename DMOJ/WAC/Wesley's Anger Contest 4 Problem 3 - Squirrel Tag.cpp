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
const int MOD = 1000000000;

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

const int MM = (1 << 16);
int n; double dp[16][MM + 5], sx[16], sy[16], vx[16], vy[16], s;

double fun(double mx, double my, double t0, int i) {
    double dx = sx[i] + vx[i] * t0 - mx, dy = sy[i] + vy[i] * t0 - my;
    double A = s * s - vx[i] * vx[i] - vy[i] * vy[i];
    double B = -2 * (dx * vx[i] + dy * vy[i]);
    double C = -dx * dx - dy * dy;
    return (-B + sqrt(B * B - 4 * A * C)) / (2 * A);
}

void solve() {

    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (1 << n); j++) {
            dp[i][j] = 1.0e20;
        }
    }
    double ans = 1.0e20;
    for (int i = 0; i < n; i++) {
        cin >> sx[i] >> sy[i] >> vx[i] >> vy[i];
        dp[i][1 << i] = fun(0, 0, 0, i);
    }
    for (int mask = 1; mask < (1 << n); mask++) {
        for (int i = 0; i < n; i++) {
            if (!(mask & (1 << i))) continue;
            for (int j = 0; j < n; j++) {
                if (mask & (1 << j)) continue;
                int new_mask = mask | (1 << j);
                double michaelx = dp[i][mask] * vx[i] + sx[i], michaely = dp[i][mask] * vy[i] + sy[i];
                dp[j][new_mask] = min(dp[j][new_mask], dp[i][mask] + fun(michaelx, michaely, dp[i][mask], j));
            }
        }
    }
    for (int i = 0; i < n; i++) ans = min(ans, dp[i][(1 << n) - 1]);
    printf("%.10f\n", ans);

}

int32_t main() {
   ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}