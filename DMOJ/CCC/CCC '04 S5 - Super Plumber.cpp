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

int m, n, dp[105][105], a[105][105];

void solve(int tc) {

    while (1) {
        cin >> m >> n; ms(dp, 0);
        if (m == 0 && n == 0) return;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                char ch; cin >> ch;
                if (ch == '*') a[i][j] = -1000000;
                else if (ch >= '0' && ch <= '9') a[i][j] = ch - '0';
                else a[i][j] = 0;
            }
        }
        for (int i = m; i >= 1; i--) {
            dp[i][1] = dp[i+1][1] + a[i][1];
        }
        for (int j = 2; j <= n; j++) {
            for (int i = 1; i <= m; i++) {
                dp[i][j] = dp[i][j-1] + a[i][j]; int sum = a[i][j];
                for (int k = i - 1; k >= 1; k--) {
                    sum += a[k][j];
                    dp[i][j] = max(dp[i][j], sum + dp[k][j-1]);
                }
                sum = a[i][j];
                for (int k = i + 1; k <= m; k++) {
                    sum += a[k][j];
                    dp[i][j] = max(dp[i][j], sum + dp[k][j-1]);
                }
            }
        }
        cout << dp[m][n] << nl;
    }

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tc = 1;// cin >> tc;
    for (int t = 0; t < tc; t++) solve(t);

    return 0;
}