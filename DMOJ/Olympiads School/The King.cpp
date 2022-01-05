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

int n, K; ll dp[11][1 << 11][101];

bool check1(int mask) {
    for (int i = 1; i < n; i++) {
        if (mask & (1 << i) && mask & (1 << (i - 1))) return false;
    }
    return true;
}

bool check2(int mask, int prev_mask) {
    for (int i = 0; i < n; i++) {
        if (mask & (1 << i)) {
            if (prev_mask & (1 << i)) return false;
            if (i < (n - 1) && (prev_mask & (1 << (i + 1)))) return false;
            if (i > 0 && (prev_mask & (1 << (i - 1)))) return false;
        }
    }
    return true;
}

int cntbits(int mask) {
    int cnt = 0; int x = mask; while (x) { cnt++; x = x & (x - 1); } return cnt;
}

void solve() {

    cin >> n >> K; dp[0][0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int prev_mask = 0; prev_mask < (1 << n); prev_mask++) {
            if (!check1(prev_mask)) continue;
            for (int mask = 0; mask < (1 << n); mask++) {
                if (!check1(mask)) continue;
                if (!check2(mask, prev_mask)) continue;
                int num = cntbits(mask);
                for (int k = 0; k <= (K - num); k++) {
                    dp[i][mask][k + num] += dp[i-1][prev_mask][k];
                }
            }
        }
    }
    ll ans = 0;
    for (int mask = 0; mask < (1 << n); mask++) {
        ans += dp[n][mask][K];
    }
    cout << ans << nl;

}

int32_t main() {
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}