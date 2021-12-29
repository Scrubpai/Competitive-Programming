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
//coordinate compression:sort(val.begin(), val.end());
//		val.resize(unique(val.begin(), val.end()) - val.begin());
#define nl '\n'
typedef unsigned long long ull;
const lld pi = 3.14159265358979323846;
const ll MOD = 1e9 + 7;

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

//dp[i][j]: # of binary search trees with n nodes and height h

int H, N; ll ans, dp[40][40];

ll fun(int i, int j) {
    if (dp[i][j] != -1) return dp[i][j];
    dp[i][j] = 0;
    //Value of root is m
    //Case 1: left subtree is height h-1
    for (int m = 1; m <= i; m++) {
        ll lft = fun(m - 1, j - 1), rit = 0;
        for (int h = 0; h <= j - 1; h++) {
            rit += fun(i - m, h);
        }
        dp[i][j] = dp[i][j] + 1LL * lft * rit;
    }
    //Case 2: right subtree is height h-1
    for (int m = 1; m <= i; m++) {
        ll lft = 0, rit = fun(i - m, j - 1);
        for (int h = 0; h <= j - 2; h++) {
            lft += fun(m - 1, h);
        }
        dp[i][j] = dp[i][j] + 1LL * lft * rit;
    }
    return dp[i][j];
}

void solve(int tc) {

    cin >> N >> H; ms(dp, -1); dp[0][0] = 1;
    for (int i = 1; i <= N; i++) dp[i][0] = 0;
    for (int i = 1; i <= H; i++) dp[0][i] = 0;
    for (int i = H; i <= N; i++) {
        ans += fun(N, i);
    }
    cout << ans << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);

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