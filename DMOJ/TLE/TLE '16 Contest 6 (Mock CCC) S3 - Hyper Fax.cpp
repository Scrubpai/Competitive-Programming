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

int n; pll houses[2005]; ll dp[2005][2005][2], psa[2005];

void solve(int tc) {

    cin >> n; ms(dp, LL_INF);
    for (int i = 1; i <= n; i++) {
        ll x, d; cin >> x >> d; houses[i] = {x, d};
    }
    sort(houses + 1, houses + 1 + n);
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        if (houses[i].first == 0) { dp[i][i][0] = dp[i][i][1] = 0; ans = houses[i].second; }
        psa[i] = psa[i-1] + houses[i].second;
    }
    for (int len = 2; len <= n; len++) {
        for (int i = 1; i + len - 1 <= n; i++) {
            int l = i, r = i + len - 1;
            if (psa[r-1] - psa[l-1] - dp[l][r-1][0] >= houses[r].first - houses[l].first) dp[l][r][1] = min(dp[l][r][1], dp[l][r-1][0] + houses[r].first - houses[l].first);
            if (psa[r-1] - psa[l-1] - dp[l][r-1][1] >= houses[r].first - houses[r-1].first) dp[l][r][1] = min(dp[l][r][1], dp[l][r-1][1] + houses[r].first - houses[r-1].first);
            if (psa[r] - psa[l] - dp[l+1][r][0] >= houses[l+1].first - houses[l].first) dp[l][r][0] = min(dp[l][r][0], dp[l+1][r][0] + houses[l+1].first - houses[l].first);
            if (psa[r] - psa[l] - dp[l+1][r][1] >= houses[r].first - houses[l].first) dp[l][r][0] = min(dp[l][r][0], dp[l+1][r][1] + houses[r].first - houses[l].first);
            if (dp[l][r][0] != LL_INF || dp[l][r][1] != LL_INF) ans = max(ans, psa[r] - psa[l-1]);
        }
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