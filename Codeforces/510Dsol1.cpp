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
//coordinate compression:sort(val.begin(), val.end());
//		val.resize(unique(val.begin(), val.end()) - val.begin());
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

const int MM = 1 << 9;
int n, l[305], c[305], dp[305][MM + 5], marked[305]; vector<int> p;

int fun(int cur, int mask) {
    if (cur == n + 1) {
        int v = p.size();
        if (mask == ((1 << v) - 1)) return 0;
        else return INF;
    }
    if (dp[cur][mask] != -1) return dp[cur][mask];
    dp[cur][mask] = INF;
    dp[cur][mask] = min({dp[cur][mask], fun(cur + 1, mask), fun(cur + 1, mask | marked[cur]) + c[cur]});
    return dp[cur][mask];
}

void solve(int tc) {

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> l[i];
    for (int i = 1; i <= n; i++) cin >> c[i];
    int ans = INF;
    for (int i = 1; i <= n; i++) {
        p.clear(); int tmp = l[i];
        for (int j = 2; j <= sqrt(l[i]); j++) {
            if (tmp % j == 0) p.push_back(j);
            while (tmp > 1 && tmp % j == 0) tmp /= j;
        }
        if (tmp > 1) p.push_back(tmp);
        for (int j = 1; j <= n; j++) {
            marked[j] = 0;
            for (int k = 0; k < p.size(); k++) {
                if (l[j] % p[k] != 0) marked[j] |= (1 << k);
            }
        }
        ms(dp, -1);
        ans = min(ans, c[i] + fun(1, 0));
    }
    if (ans == INF) cout << -1 << nl;
    else cout << ans << nl;

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