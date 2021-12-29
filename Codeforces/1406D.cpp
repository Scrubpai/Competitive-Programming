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

const int MM = 1e5 + 5;
int n, l, r, q; ll bit[MM], x, a[MM], lft, rit;

ll query(int x) {
    ll sum = 0;
    for (int i = x; i >= 1; i -= i&-i) sum += bit[i];
    return sum;
}

void update(int pos, ll v) {
    for (int i = pos; i <= n; i += i&-i) {
        bit[i] += v;
    }
}

void solve(int tc) {

    cin >> n;
    ll ans = 0; a[0] = INF;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] > a[i-1]) ans += (a[i] - a[i-1]);
    }
    if (a[1] + ans >= 0) { cout << (a[1] + ans + 1) / 2 << nl; }
    else cout << (a[1] + ans) / 2 << nl;
    cin >> q;
    while (q--) {
        cin >> l >> r >> x;
        lft = (a[l] + query(l)) - (a[l-1] + query(l-1));
        rit = (a[r+1] + query(r+1)) - (a[r] + query(r));
        if (l != 1) ans -= max(lft, 0LL); if (r != n) ans -= max(rit, 0LL);
        update(l, x); update(r+1, -x);
        lft = (a[l] + query(l)) - (a[l-1] + query(l-1));
        rit = (a[r+1] + query(r+1)) - (a[r] + query(r));
        if (l != 1) ans += max(lft, 0LL); if (r != n) ans += max(rit, 0LL);
        ll cur = a[1] + query(1) + ans;
        if (cur >= 0) { cout << (cur + 1) / 2 << nl; }
        else cout << cur / 2 << nl;
    }

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tc = 1; //cin >> tc;
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