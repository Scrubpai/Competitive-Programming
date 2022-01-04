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

//remember to remove ios stuff if i use scanf LOL

//printf("%05lld\n", x); --> print last 5 digits including 0's
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

int n, h[16], dp[(1 << 15) + 1], T = 5;

bool check(int mask) {
    bool inc = true, dec = true; int prev = -1;
    for (int i = 0; i < n; i++) {
        if (!(mask & (1 << i))) {
            if (prev == -1) { prev = i; continue; }
            if (h[i] > h[prev]) { dec = false; prev = i; }
            if (h[i] < h[prev]) { inc = false; prev = i; }
        }
    }
    return (dec || inc);
}

int fun(int mask) {
    if (check(mask)) return dp[mask] = 0;
    if (dp[mask] != -1) return dp[mask];
    int ret = 0;
    for (int i = 0; i < n; i++) {
        if (!(mask & (1 << i))) { ret = max(ret, ((fun(mask | (1 << i))) + 1) % 2); }
    }
    return dp[mask] = ret;
}

void solve() {

    while (T--) {
        string ans = "";
        for (int t = 0; t < 3; t++) {
            cin >> n; ms(dp, -1);
            for (int i = 0; i < n; i++) cin >> h[i];
            if (fun(0) == 0) ans += 'B';
            else ans += 'A';
        }
        cout << ans << nl;
    }

}

int32_t main() {
  //  ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}