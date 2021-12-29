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

const int MM = 1e5 + 5;
int n, d, m, a[MM], cnt; ll psamx[MM], psamn[MM], sum;

void solve() {

    cin >> n >> d >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i]; sum += a[i];
        if (a[i] > m) cnt++;
    }
    if (cnt == 0) { cout << sum << nl; return; }
    sort(a + 1, a + 1 + n, greater<int>());
    int smaller = n - cnt;
    for (int i = 1; i <= n; i++) {
        if (i > cnt) psamn[i-cnt] = psamn[i-cnt-1] + a[i];
        else psamx[i] = psamx[i-1] + a[i];
    }
    ll ans = 0;
    for (int i = 1; i <= cnt; i++) {
        //take i big items
        if (1LL * n - (1LL * (i-1) * 1LL * (d+1)+1) < 0) continue;
        ll cur = psamx[i]; int rem = min(n - ((i-1)*(d+1)+1), smaller);
        ans = max(ans, cur + psamn[rem]);
    }
    cout << ans << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}