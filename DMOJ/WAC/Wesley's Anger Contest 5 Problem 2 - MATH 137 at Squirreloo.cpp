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
#define INF 0x3f3f3f3f // for int
#define LL_INF 0x3f3f3f3f3f3f3f3f // for ll
#define gl(x) getline(cin, (x))
#define sz(x) (int)(x.size())
#define af(x) x.begin(), x.end()
#define ms(x, y) memset(x, y, sizeof(x))
#define mpp make_pair
#define pb push_back
#define AUT auto
#define nl '\n'
typedef unsigned long long ull;
const int MOD = 1e9 + 7;

ll gcd(ll a, ll b){return b == 0 ? a : gcd(b, a % b);}
ll lcm(ll a, ll b){return a*b/gcd(a,b);}
ll pwmd(ll b, ll exp) {
    ll ret = 1;
    while (exp > 0) {
        if (exp % 2 == 1) ret = (ret * b) % MOD;
        exp /= 2;
        b = (b * b) % MOD;
    }
    return ret;
}

const int MM = 2e5 + 5;
int n, q, a[MM], mn[MM], mx[MM];

void solve() {

    cin >> n >> q; ms(mn, INF); ms(mx, -INF);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = n; i >= 1; i--) {
        mx[i] = max(mx[i+1], a[i]);
        mn[i] = min(mn[i+1], a[i]);
    }
    while (q--) {
        int x, y, l, r; cin >> x >> y;
        l = x - y, r = x + y; int lo = 1, hi = n; int ans = n + 1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (mn[mid] >= l && mx[mid] <= r) {
                ans = min(ans, mid); hi = mid-  1;
            } else {
                lo = mid + 1;
            }
        }
        cout << n - ans + 1 << nl;
    }

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}