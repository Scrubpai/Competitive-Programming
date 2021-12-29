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
typedef double ld;
typedef long double lld;
#define INF 0x3f3f3f3f // for int
#define LL_INF 0x3f3f3f3f3f3f3f3f // for ll
#define ms(x, y) memset(x, y, sizeof(x))
//coordinate compression:sort(val.begin(), val.end());
//		val.resize(unique(val.begin(), val.end()) - val.begin());
#define nl '\n'
typedef unsigned long long ull;
const lld pi = 3.14159265358979323846;
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
ll n, q, ans, x, tmp, row[MM], col[MM];
//row: closet row for a given column
//col: closest col for a given row

ll query(ll bit[], int p) {
    ll ret = 0;
    for (; p >= 1; p -= p&-p) ret += bit[p];
    return ret;
}

void update(ll bit[], ll v, int p) {
    for (; p <= n; p += p&-p) bit[p] += v;
}

void solve(int tc) {

    cin >> n >> q; ans = (n - 2) * (n - 2); update(row, n, 1); update(col, n, 1);
    while (q--) {
        cin >> tmp >> x;
        if (tmp == 1) {
            ll closest = query(row, x); ans -= (closest - 2);
            //update
            ll prev = query(col, 1);
            if (prev > x) {
                update(col, -(prev - x), 1);
                update(col, prev - x, closest);
            }
        } else {
            ll closest = query(col, x); ans -= (closest - 2);
            //update
            ll prev = query(row, 1);
            if (prev > x) {
                update(row, -(prev - x), 1);
                update(row, prev - x, closest);
            }
        }
    }
    cout << ans << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tc = 1;// cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);

    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
*/