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

ll n, a[1005], b[1005], dp[1005][1005]; string s, t;

void solve(int tc) {

    cin >> n >> s;
    for (int i = 1; i <= n; i++) cin >> a[i];
    cin >> t;
    for (int i = 1; i <= n; i++) cin >> b[i];
    s = " " + s; t = " " + t;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if ((s[i] == 'W' && t[j] == 'L' && a[i] > b[j]) || (s[i] == 'L' && t[j] == 'W' && a[i] < b[j])) dp[i][j] = max({dp[i-1][j-1] + a[i] + b[j], dp[i-1][j], dp[i][j-1]});
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    cout << dp[n][n] << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tc = 1; //cin >> tc;
    for (int t = 0; t < tc; t++) solve(t);

    return 0;
}