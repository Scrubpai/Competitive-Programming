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

int T, n; vector<vector<int>> dp; vector<int> seg[6005];

int fun(int l, int r) {
    if (dp[l][r] != -1) return dp[l][r];
    dp[l][r] = 0;
    if (l > r) return dp[l][r];
    bool add = count(seg[l].begin(), seg[l].end(), r);
    dp[l][r] = add + (l + 1 > r ? 0 : fun(l + 1, r));
    for (int rit : seg[l]) {
        if (rit >= r) { continue; }
        dp[l][r] = max(dp[l][r], add + fun(l, rit) + (rit + 1 > r ? 0 : fun(rit + 1, r)));
    }
    return dp[l][r];
}

void solve() {

    cin >> T;
    while (T--) {
        cin >> n; vector<int> val, l(n), r(n);
        for (int i = 0; i < n; i++) {
            cin >> l[i] >> r[i];
            val.push_back(l[i]); val.push_back(r[i]);
        }
        sort(val.begin(), val.end());
        val.resize(unique(val.begin(), val.end()) - val.begin());
        int sz = val.size();
        for (int i = 0; i < sz; i++) seg[i].clear();
        for (int i = 0; i < n; i++) {
            l[i] = lower_bound(val.begin(), val.end(), l[i]) - val.begin();
            r[i] = lower_bound(val.begin(), val.end(), r[i]) - val.begin();
            seg[l[i]].push_back(r[i]);
        }
        dp = vector<vector<int>>(sz, vector<int>(sz, -1));
        cout << fun(0, sz - 1) << nl;
    }

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}