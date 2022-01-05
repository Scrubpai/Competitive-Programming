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
#define f first
#define s second
#define nl '\n'
typedef unsigned long long ull;
const int MN = 500005;
const int MOD = 1000000007;

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
                                            //which side you end up on
int n, l; vector<ll> p; ll dp[2005][2005][2];

void solve() {

    cin >> n >> l; p.push_back(l); ms(dp, INF);
    for (int i = 0; i < n; i++) {
        ll pos; cin >> pos; p.push_back(pos);
    }
    sort(p.begin(), p.end()); n++;
    int start = lower_bound(p.begin(), p.end(), l) - p.begin(); dp[start][start][0] = 0; dp[start][start][1] = 0;

    for (int len = 1; len < n; len ++) {
        for (int i = 0; i + len < n; i++) {
            int j = i + len;

            dp[i][j][0] = min(dp[i+1][j][0] + (n - len) * (p[i+1] - p[i]), dp[i+1][j][1] + (n - len) * (p[j] - p[i]));
            dp[i][j][1] = min(dp[i][j-1][0] + (n - len) * (p[j] - p[i]), dp[i][j-1][1] + (n - len) * (p[j] - p[j-1]));
        }
    }

    cout << min(dp[0][n-1][0], dp[0][n-1][1]) << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}