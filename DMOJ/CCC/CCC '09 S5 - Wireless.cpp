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
//#define sz(a) sizeof(a)/sizeof(a[0])
//#define AUT auto
#define f first
#define s second
#define nl '\n'
typedef unsigned long long ull;
const int MN = 1e6 + 5;
const int MOD = 100000;

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

int m, n, k; ll psa[30005][1005];

void solve() {

    cin >> m >> n >> k;
    for (int i = 1; i <= k; i++) {
        int x, y, r, b; cin >> y >> x >> r >> b;
        for (int p = max(x - r, 1); p <= min(m, x + r); p++) {
            int lft = max(1, y - (int)sqrt((r * r) - (x - p) * (x - p)));
            int rit = min(n, y + (int)sqrt((r * r) - (x - p) * (x - p)));
            psa[p][lft] += b; psa[p][rit + 1] -= b;
        }
    }

    ll mx = 0, cnt = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            psa[i][j] += psa[i][j-1];
            if (psa[i][j] > mx) { mx = psa[i][j]; cnt = 1;}
            else if (psa[i][j] == mx) { cnt++; }
        }
    }
    cout << mx << nl << cnt << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}