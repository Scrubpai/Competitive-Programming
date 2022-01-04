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

int n, h[51], e[51], p[51], dp[2][1005], cnt[2][1005], s;

void solve(int tc) {

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> h[i] >> e[i] >> p[i];
    cin >> s;
    for (int i = 1; i <= n; i++) {
        int cur = 0;
        for (int j = 1, val = h[i], prep = p[i]; val > 0 && prep <= s; j++, val -= e[i], prep += p[i]) {
            cur += val;
            for (int k = prep; k <= s; k++) {
                if (dp[1][k] < dp[0][k-prep] + cur) {
                    dp[1][k] = dp[0][k-prep] + cur; cnt[1][k] = cnt[0][k-prep] + j;
                } else if (dp[1][k] == dp[0][k-prep] + cur) {
                    cnt[1][k] = min(cnt[1][k], cnt[0][k-prep] + j);
                }
            }
        }
        for (int j = 0; j <= s; j++) dp[0][j] = dp[1][j], cnt[0][j] = cnt[1][j];
    }
    cout << dp[0][s] << nl << cnt[0][s] << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tc = 1; //cin >> tc;
    for (int t = 0; t < tc; t++) solve(t);

    return 0;
}