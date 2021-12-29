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

//dp[i][j][k] = minimum number of shots to kill archers starting from the ith archer
//when the previous archer has j health points and the no. of
//direct shots made on the previous archer is equal to k

//hlth[i][j][k]: hp left after considering direct attacks on the ith soldier

//shots[i][j][k]: # of direct shots on the ith soldier

int n, a, b, h[15], dp[20][20][20], hlth[20][20][20], shots[20][20][20]; vector<int> ord;

int fun(int i, int j, int k) {
    if (i >= n) {
        if (j > 0) return 10000;
        else return 0;
    }
    if (dp[i][j][k] != -1) return dp[i][j][k];
    dp[i][j][k] = INF; int tmp = h[i];
    int op = 0; if (h[i-1] % b != 0) op++;
    for (int t = h[i-1] / b + op; t <= max(h[i-1] / b, tmp / a) + 1; t++) {
        h[i] = max(tmp - k * b - t * a, 0);
        int cur = t + fun(i+1, h[i], t);
        if (dp[i][j][k] > cur) {
            dp[i][j][k] = cur; hlth[i][j][k] = h[i]; shots[i][j][k] = t;
        }
        h[i] = tmp;
    }
    return dp[i][j][k];
}

void compute_result(int i, int j, int k) {
    if (i == n) return;
    int num = shots[i][j][k];
    while (num--) ord.push_back(i);
    compute_result(i+1, hlth[i][j][k], shots[i][j][k]);
}

void solve(int tc) {

    cin >> n >> a >> b; ms(dp, -1);
    for (int i = 1; i <= n; i++) { cin >> h[i]; h[i]++; }
    while (h[1] > 0) { h[1] -= b; h[2] -= a; h[3] -= b; ord.push_back(2); }
    while (h[n] > 0) { h[n] -= b; h[n-1] -= a; h[n-2] -= b; ord.push_back(n-1); }
    for (int i = 1; i <= n; i++) h[i] = max(h[i], 0);

    fun(2, 0, 0);
    compute_result(2, 0, 0);
    cout << ord.size() << nl;
    for (int pos : ord) cout << pos << " ";

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