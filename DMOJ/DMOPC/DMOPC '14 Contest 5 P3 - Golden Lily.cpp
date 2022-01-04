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

int R, C, d[1005][1005], dp[1005][1005], fx, fy;

void solve(int tc) {

    cin >> C >> R; ms(dp, INF);
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            cin >> d[i][j];
        }
    }
    cin >> fy >> fx; fy++; fx++; dp[1][1] = d[1][1];
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            dp[i][j] = min({dp[i][j], dp[i-1][j] + d[i][j], dp[i][j-1] + d[i][j]});
        }
        for (int j = C; j >= 1; j--) {
            dp[i][j] = min(dp[i][j], dp[i][j+1] + d[i][j]);
        }
    }
    cout << dp[fx][fy] << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tc = 1; //cin >> tc;
    for (int t = 0; t < tc; t++) solve(t);

    return 0;
}