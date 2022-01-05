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
const int MN = 5000;
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

int dp[1001][1001]; int N, M; string A, B;

void solve() {

    cin >> N >> M >> A >> B;
    for (int i=1; i<=M; i++) dp[0][i] = dp[0][max(i-3, 0)] + 1;
    for (int i=1; i<=N; i++) dp[i][0] = dp[max(i-3, 0)][0] + 1;
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=M; j++) {
            if (A[i-1]==B[j-1]) { dp[i][j] = dp[i-1][j-1]; continue; }
            dp[i][j] = min(dp[i-1][j] + 1, min(dp[max(i-2, 0)][j] + 1, min(dp[max(i-3, 0)][j] + 1, min(dp[i][j-1] + 1, min(dp[i][max(j-2, 0)] + 1, min(dp[i][max(j-3, 0)] + 1, dp[i-1][j-1] + 1))))));
        }
    }
    cout << dp[N][M] << nl;

}

int32_t main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}