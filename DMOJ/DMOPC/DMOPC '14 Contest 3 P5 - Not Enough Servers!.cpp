#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<string> vs;
typedef complex<double> pnt;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define rep1(i, a, n) for (int i=a; i<=n; i++)
#define per(i,a,n) for (int i=a-1;i>=n;i--)
#define per1(i,a,n) for (int i=a;i>=n;i--)
#define endl '\n'
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
#define f first
#define s second
#define nl '\n'
typedef unsigned long long ull;
const int MN = (int)(pow(2, 20));
const int MOD = 1e9 + 7;

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

int n, m, bit[50], res = 0; int dp[1100000]; int pre[1100000]; int use[1100000];

void solve() {

    cin >> n >> m; ms(dp, INF); dp[0] = 0;
    for (int i=0; i<n; i++) {
        char c[21][51]; bool ac = true;
        for (int j=0; j<m; j++) {
            cin >> c[i][j]; bit[j] <<= 1;
            if (c[i][j]=='X') {
                ac = false; bit[j] |= 1;
            }
        }
        res = res << 1 | (ac? 0:1);
    }
    if (res == 0) { cout << 1 << nl << 1 << nl; return; }
    for (int i=0; i<m; i++) {
        for (int mask=0; mask<(1 << n); mask++) {
            int newmask = mask | bit[i];
            if (dp[newmask] > 1 + dp[mask]) {
                dp[newmask] = 1 + dp[mask];
                pre[newmask] = mask;
                use[newmask] = i + 1;
            }
        }
    }

    cout << dp[res] << nl;
    for (int mask=res; mask!=0; mask=pre[mask]) {
        cout << use[mask] << " ";
    }
    cout << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}