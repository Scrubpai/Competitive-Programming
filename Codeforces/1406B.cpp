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
const int MOD = 1000000000;

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
int n; vector<ll> pos, neg;

void solve(int tc) {

    cin >> n; neg.clear(); pos.clear();
    for (ll i = 1, x; i <= n; i++) {
        cin >> x;
        if (x >= 0) pos.push_back(x);
        else neg.push_back(x);
    }
    sort(neg.begin(), neg.end()); sort(pos.rbegin(), pos.rend());
    ll ans = -LL_INF;
    for (int i = 0; i <= 5; i++) {
        ll cur = 1; //chose i negative
        if (i > neg.size()) break;
        if (5 - i > pos.size()) continue;
        if (i % 2 == 1) {
            int x = neg.size() - 1, y = neg.size() - i;
            for (int j = x; j >= y; j--) {
                cur *= 1LL * neg[j];
            }
            int rem = 5 - i;
            for (int j = 0; j < rem; j++) cur *= 1LL * pos[j];
        } else {
            for (int j = 0; j < i; j++) {
                cur *= 1LL * neg[j];
            }
            int rem = 5 - i;
            for (int j = 0; j < rem; j++) cur *= 1LL * pos[j];
        }
        ans = max(ans, cur);
    }
    cout << ans << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tc = 1; cin >> tc;
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