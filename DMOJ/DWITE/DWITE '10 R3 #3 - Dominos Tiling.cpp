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
const int MOD = 1000000;

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

int T = 5; int n;
int dp[31]; //how many ways can you tile a 3xi grid

int fun2(int m) { //how many ways can you tile a 3xm grid with a corner tile removed
    if (m==0) return 0;
    if (m==1) return 1;
    if (dp[m]!=-1) return dp[m];
    return dp[m] = (dp[m-1] + fun2(m-2)) % MOD;
}

int fun(int m) { //how many ways can you tile a 3xm grid
    if (m==0) return 1;
    if (m==1) return 0;
    if (dp[m]!=-1) return dp[m];
    return dp[m] = (fun(m-2) + 2 * fun2(m-1)) % MOD;
}

void solve() {

    for (int i=0; i<=30; i++) dp[i] = -1;
    fun(30);
    while (T--) {
        cin >> n;
        if (n%2==1 || n==0) cout << 0 << nl;
        else cout << dp[n] << nl;
    }

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}