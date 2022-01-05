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

const int MM = (1 << 10) + 5;
int L, R, W, dp[MM][MM][2], wl[MM], wr[MM], l[MM], r[MM];
//dp[i][j][0]: 0 --> remove left
//dp[i][j][1]: 1 --> remove right

void solve(int tc) {

    cin >> L >> R >> W; ms(dp, INF); dp[0][0][0] = dp[0][0][1] = 1;
    for (int i = 0; i < L; i++) cin >> l[i];
    for (int i = 0; i < R; i++) cin >> r[i];
    for (int mask = 1; mask < (1 << L); mask++) {
        int sum = 0;
        for (int j = 0; j < L; j++) {
            if (mask & (1 << j)) sum += l[j];
        }
        wl[mask] = sum;
    }
    for (int mask = 1; mask < (1 << R); mask++) {
        int sum = 0;
        for (int j = 0; j < R; j++) {
            if (mask & (1 << j)) sum += r[j];
        }
        wr[mask] = sum;
    }
    for (int lft = 0; lft < (1 << L); lft++) {
        for (int rit = 0; rit < (1 << R); rit++) {
            if (abs(wr[rit] - wl[lft]) > W) continue;
            for (int i = 0; i < L; i++) {
                if (!(lft & (1 << i))) continue;
                int nmask = lft ^ (1 << i);
                dp[lft][rit][0] = min(dp[lft][rit][0], dp[nmask][rit][0]);
                dp[lft][rit][0] = min(dp[lft][rit][0], dp[nmask][rit][1] + 1);
            }
            for (int i = 0; i < R; i++) {
                if (!(rit & (1 << i))) continue;
                int nmask = rit ^ (1 << i);
                dp[lft][rit][1] = min(dp[lft][rit][1], dp[lft][nmask][1]);
                dp[lft][rit][1] = min(dp[lft][rit][1], dp[lft][nmask][0] + 1);
            }
        }
    }
    cout << min(dp[(1 << L) - 1][(1 << R) - 1][0], dp[(1 << L) - 1][(1 << R) - 1][1]) << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);

    return 0;
}