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

ll R, G, B, r[205], g[205], b[205], dp[205][205][205];

ll fun(int i, int j, int k) {
    if ((i > R && j > G) || (i > R && k > B) || (j > G && k > B)) return 0;
    if (dp[i][j][k] != -1) return dp[i][j][k];
    ll ret = 0;
    if (i <= R && j <= G) ret = max(ret, r[i] * g[j] + fun(i + 1, j + 1, k));
    if (i <= R && k <= B) ret = max(ret, r[i] * b[k] + fun(i + 1, j, k + 1));
    if (j <= G && k <= B) ret = max(ret, g[j] * b[k] + fun(i, j + 1, k + 1));
    return dp[i][j][k] = ret;
}

void solve(int tc) {

    cin >> R >> G >> B; ms(dp, -1);
    for (int i = 1; i <= R; i++) cin >> r[i];
    for (int i = 1; i <= G; i++) cin >> g[i];
    for (int i = 1; i <= B; i++) cin >> b[i];
    sort(r + 1, r + 1 + R, greater<int>()); sort(b + 1, b + 1 + B, greater<int>()); sort(g + 1, g + 1 + G, greater<int>());
    cout << fun(1, 1, 1) << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tc = 1;
   // cin >> tc;
    for (int t = 0; t < tc; t++) solve(t);
    return 0;
}