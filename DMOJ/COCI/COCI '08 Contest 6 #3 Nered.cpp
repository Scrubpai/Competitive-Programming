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

int n, m, psa[105][105], l, w;

void solve(int tc) {

    cin >> n >> m;
    for (int i = 1, r, c; i <= m; i++) {
        cin >> r >> c;
        psa[r][c] = 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            psa[i][j] += psa[i-1][j] + psa[i][j-1] - psa[i-1][j-1];
        }
    }
    int ans = 0;
    for (int i = 1; i <= m; i++) {
        if (m % i != 0) continue;
        l = i, w = m / i;
        for (int r = 1; r + l - 1 <= n; r++) {
            for (int c = 1; c + w - 1 <= n; c++) {
                int r1 = r, c1 = c, r2 = r + l - 1, c2 = c + w - 1;
                ans = max(ans, psa[r2][c2] - psa[r2][c1-1] - psa[r1-1][c2] + psa[r1-1][c1-1]);
            }
        }
    }
    cout << m - ans << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);

    return 0;
}