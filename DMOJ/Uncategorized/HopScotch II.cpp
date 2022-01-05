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

const int MM = (1 << 23) + 5;
ll dp[MM], dq[MM], lft, rit, pre[MM], a[MM]; int n, k; ll val;

void solve() {

    cin >> n >> k; int num = 0;
    for (int i = 1; i <= n + 1; i++) {
        if (i != n + 1) scanf("%lld", &val);
        if (dq[lft] == i - k - 1) lft++;
        dp[i] = dp[dq[lft]] + val; pre[i] = dq[lft];
        while (lft <= rit && dp[i] <= dp[dq[rit]]) rit--;
        dq[++rit] = i; val = 0;
    }
    cout << dp[n + 1] << nl;
    for (int i = n + 1; i; i = pre[i]) a[num++] = pre[i];
    for (int i = num - 2; i >= 0; i--) cout << a[i] << " ";
    cout << nl;

}

int32_t main() {
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}