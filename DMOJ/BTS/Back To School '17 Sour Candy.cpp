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
int n, s1[MM], s2[MM], dp[MM], bit[MM], idx[MM]; unordered_map<int, int> mp;

void update(int p, int v) {
    for (; p <= n; p += p&-p) bit[p] += v;
}

int query(int p) {
    int ret = 0;
    for (; p >= 1; p -= p&-p) ret += bit[p];
    return ret;
}

void solve(int tc) {

    cin >> n; ms(dp, -1);
    for (int i = 1; i <= n; i++) cin >> s1[i];
    for (int i = 1; i <= n; i++) { cin >> s2[i]; mp[s2[i]] = i; }
    for (int i = 1; i <= n; i++) {
        s1[i] = mp[s1[i]]; idx[s1[i]] = i;
        if (dp[s1[i]-1] == -1) dp[s1[i]] = 1;
        else dp[s1[i]] = dp[s1[i]-1] + 1;
    }
    int lo = -1, hi = -1, mx = 0;
    for (int i = 1; i <= n; i++) {
        if (dp[i] > mx) {
            mx = dp[i];
            hi = i; lo = i - dp[i] + 1;
        }
    }
    cout << n - (hi - lo + 1) << nl;
    hi++; lo--;
    while (hi <= n) {
        int p = query(idx[hi]) + idx[hi];
        cout << "B " << p << nl;
        update(idx[hi], -1);
        hi++;
    }
    while (lo >= 1) {
        int p = query(idx[lo]) + idx[lo];
        cout << "F " << p << nl;
        update(1, 1); update(idx[lo] + 1, -1);
        lo--;
    }

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);

    return 0;
}