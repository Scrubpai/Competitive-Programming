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
#define lb lower_bound
#define ub upper_bound
#define mpp make_pair
#define pb push_back
//#define sz(a) sizeof(a)/sizeof(a[0])
//#define AUT auto
//#define f first
//#define s second
//coordinate compression:sort(val.begin(), val.end());
//		val.resize(unique(val.begin(), val.end()) - val.begin());
#define nl '\n'
typedef unsigned long long ull;
const int MOD = 10;

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

int T, r, g, b, w;

void solve() {

    cin >> T;
    while (T--) {
        cin >> r >> g >> b >> w; int odd = 0, even = 0;
        if (r % 2 == 1) odd++;
        else even++;
        if (g % 2 == 1) odd++;
        else even++;
        if (b % 2 == 1) odd++;
        else even++;
        if (w % 2 == 1) odd++;
        else even++;
        if (even == 4 || (odd == 1 && even == 3)) { cout << "Yes" << nl; continue; }
        int mn = min(r, min(g, b));
        if (mn == 0) { cout << "No" << nl; continue; }
        r--; g--; b--; w++;
        odd = 0; even = 0;
        if (r % 2 == 1) odd++;
        else even++;
        if (g % 2 == 1) odd++;
        else even++;
        if (b % 2 == 1) odd++;
        else even++;
        if (w % 2 == 1) odd++;
        else even++;
        if (even == 4 || (odd == 1 && even == 3)) { cout << "Yes" << nl; continue; }
        else cout << "No" << nl;
    }

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}