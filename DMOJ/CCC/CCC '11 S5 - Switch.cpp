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
//#define sz(a) sizeof(a)/sizeof(a[0])
//#define AUT auto
//#define f first
//#define s second
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

int k, a[26], dp[26], psa[26];

void solve() {

    cin >> k; ms(dp, INF); int ans = 0; dp[0] = 0;
    for (int i = 1; i <= k; i++) { cin >> a[i]; psa[i] = psa[i-1] + a[i]; }
    if (psa[k] == 0) { cout << 0 << nl; return; }
    for (int i = 1; i <= k; i++) {
        if (i <= 4) { dp[i] = min(dp[i], 4 - psa[i]); }
        if (!a[i]) { dp[i] = dp[i-1]; continue; }
        for (int j = i - 3; j >= max(1, i - 6); j--) {
            int len = i - j + 1; if (a[j-1]) continue;
            if (len == 4 || len == 5 || (len == 6 && (a[i - 3] != 1 || a[i - 2] != 1)) || (len == 7 && (a[i - 3] != 1))) dp[i] = min(dp[i], dp[j - 1] + len - (psa[i] - psa[j - 1]));
            else if (len == 6 && (a[i - 3] == 1 && a[i - 2] == 1)) dp[i] = min(dp[i], dp[j - 1] + 4);
            else if (len == 7 && a[i - 3] == 1) {
                int v1 = psa[i-3] - psa[i-7], v2 = psa[i] - psa[i-4];
                dp[i] = min(dp[i], dp[j-1] + max(v1, v2) + 4 - min(v1, v2));
            }
        }
        if (dp[i] == INF) dp[i] = 3 + dp[i - 1];
        ans = dp[i];
    }
    cout << ans << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}