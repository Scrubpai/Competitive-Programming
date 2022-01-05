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

int n, t; ll psa[(int)1e5 + 5][3];

void solve() {

    cin >> n >> t;
    for (int i = 0; i < n; i++) {
        ll l, r, a, b, c; cin >> l >> r >> a >> b >> c;
        psa[l][0] += c; psa[l+1][1] += b; psa[l+1][1] += a; psa[l+2][1] += 2 * a; psa[l+3][2] += 2 * a;
        psa[r+1][0] -= (a * (r-l) * (r-l) + b * (r-l) + c); psa[r+1][1] -= b; psa[r+1][2] -= 2 * a; psa[r+1][1] -= a + (r - l - 1) * 2 * a;
    }
    for (int i = 1; i <= t; i++) {
        psa[i][2] += psa[i-1][2]; psa[i][1] += (psa[i-1][1] + psa[i][2]); psa[i][0] += (psa[i-1][0] + psa[i][1]);
        cout << psa[i][0] << " ";
    }

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}