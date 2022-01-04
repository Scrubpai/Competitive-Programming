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
//#define f first
//#define s second
#define nl '\n'
typedef unsigned long long ull;
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

const int MM = 500005;
int n, psa[655][655]; pii a[MM];

void solve() {

    cin >> n;
    for (int i = 1; i <= n; i++) {
        int p1, p2; cin >> p1 >> p2; a[i] = {p1, p2}; p1++; p2++; psa[p1][p2]++;
    }
    for (int i = 1; i <= 651; i++) {
        for (int j = 1; j <= 651; j++) {
            psa[i][j] += psa[i-1][j] + psa[i][j-1] - psa[i-1][j-1];
        }
    }
    for (int i = 1; i <= n; i++) {
        int r = a[i].first, c = a[i].second; r++; c++;
        int hi = psa[651][651] - psa[651][c] - psa[r][651] + psa[r][c] + 1;
        int lo = psa[r - 1][c - 1]; lo = n - lo;

        if (r == 651) lo -= (psa[1][c] - psa[1][c-1]);
        if (c == 651) lo -= (psa[r][1] - psa[r-1][1]);

        cout << hi << " " << lo << nl;
    }

}

int32_t main() {
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}