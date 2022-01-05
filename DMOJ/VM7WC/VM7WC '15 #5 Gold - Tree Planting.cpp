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

ll N, R, C, t, x, bit[4005][4005]; pii mp[4005][4005];

void update(int r, int c, int v) {
    for (int i = c; i <= 4000; i += i&-i) bit[r][i] += v;
}

ll query(int r, int c) {
    ll sum = 0;
    for (int i = c; i >= 1; i -= i&-i) sum = (sum + bit[r][i]) % MOD;
    return sum % MOD;
}

void solve(int tc) {

    for (int i = 1; i <= 4000; i++) {
        int tmp = 1;
        for (int j = i - 1; j >= 0; j--) {
            int r = i - j, c = 1 + j;
            mp[r][c] = {i, tmp}; tmp++;
        }
    }
    cin >> N;
    ll ans = 0;
    while (N--) {
        int op; cin >> op;
        if (op == 1) {
            cin >> C >> R >> t;
            update(mp[R][C].first, mp[R][C].second, t);
        } else if (op == 2) {
            cin >> C >> R >> x;
            int r2 = R + x, c2 = C - x;
            ans = (ans + query(mp[r2][c2].first, mp[r2][c2].second) - query(mp[R][C].first, mp[R][C].second - 1)) % MOD;
        }
    }
    cout << ans % MOD << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);

    return 0;
}