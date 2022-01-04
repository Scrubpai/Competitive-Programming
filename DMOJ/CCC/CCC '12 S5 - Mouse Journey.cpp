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
//#define sz(a) sizeof(a)/sizeof(a[0])
//#define AUT auto
#define f first
#define s second
#define nl '\n'
typedef unsigned long long ull;
const int MN = 1e6 + 5;
const int MOD = 998244353;

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

int R, C, K; int dp[26][26]; bool check[26][26];

void solve() {

    cin >> R >> C >> K;
    rep(i, 0, K) {
        int r, c; cin >> r >> c; check[r][c] = true;
    }
    dp[1][1] = 1;
    rep1(i, 1, R) {
        rep1(j, 1, C) {
            if (!check[i-1][j]) dp[i][j] += dp[i-1][j];
            if (!check[i][j-1]) dp[i][j] += dp[i][j-1];
        }
    }
    cout << dp[R][C] << nl;

}

int32_t main() {
    solve();
    return 0;
}