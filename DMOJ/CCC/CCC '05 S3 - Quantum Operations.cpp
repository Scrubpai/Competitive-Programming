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
const ll MOD = 1e9 + 7;

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

ll n, r, c, p, q, ans[1500][1500], tmpa[1500][1500], tmpb[1500][1500], row[1500], col[1500];

void solve(int tc) {

    cin >> n >> r >> c; p = r; q = c;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> ans[i][j];
        }
    }
    for (int i = 1; i < n; i++) {
        cin >> r >> c;
        for (int j = 0; j < p; j++) {
            for (int k = 0; k < q; k++) {
                tmpa[j][k] = ans[j][k];
            }
        }
        for (int j = 0; j < r; j++) {
            for (int k = 0; k < c; k++) {
                cin >> tmpb[j][k];
            }
        }
        for (int j = 0; j < p * r; j++) {
            for (int k = 0; k < q * c; k++) {
                ans[j][k] = 1LL * tmpa[j/r][k/c] * tmpb[j%r][k%c];
            }
        }
        p *= r; q *= c;
    }
    ll mn = INF, mx = -INF, mn_row_sum = INF, mx_row_sum = -INF, mn_col_sum = INF, mx_col_sum = -INF; 
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < q; j++) {
            mn = min(mn, ans[i][j]);
            mx = max(mx, ans[i][j]);
            row[i] += ans[i][j];
            col[j] += ans[i][j];
        }
    }
    for (int i = 0; i < p; i++) mn_row_sum = min(mn_row_sum, row[i]), mx_row_sum = max(mx_row_sum, row[i]);
    for (int i = 0; i < q; i++) mn_col_sum = min(mn_col_sum, col[i]), mx_col_sum = max(mx_col_sum, col[i]);
    cout << mx << nl << mn << nl << mx_row_sum << nl << mn_row_sum << nl << mx_col_sum << nl << mn_col_sum << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tc = 1; //cin >> tc;
    for (int t = 0; t < tc; t++) solve(t);

    return 0;
}