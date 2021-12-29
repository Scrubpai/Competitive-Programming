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

//dp[i][j][k] = max # of subsequences of t if we consider the **first i characters** and we have made j replacements and we have k t[0] chars
//string "abc"; index of 'c' is 2 <-- in dp state, i = 3

int n, K, dp[205][205][205]; string s, t;

void solve(int tc) {

    cin >> n >> K >> s >> t; ms(dp, -INF); dp[0][0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= K; j++) {
            for (int k = 0; k <= i; k++) {
                //dont change s[i]
                int n1 = (s[i] == t[0]), n2 = (s[i] == t[1]), n3 = (t[0] == t[1]);
                dp[i+1][j][k+n1] = max(dp[i+1][j][k+n1], dp[i][j][k] + (n2 ? k : 0));
                if (j < K) {
                    //s[i] --> t[0]
                    if (s[i] != t[0]) {
                        dp[i+1][j+1][k+1] = max(dp[i+1][j+1][k+1], dp[i][j][k] + (n3 ? k : 0));
                    }
                    //s[i] --> t[1]
                    if (s[i] != t[1]) {
                        dp[i+1][j+1][k] = max(dp[i+1][j+1][k], dp[i][j][k] + k);
                    }
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= K; i++) {
        for (int j = 0; j <= n; j++) {
            ans = max(ans, dp[n][i][j]);
        }
    }
    cout << ans << nl;

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