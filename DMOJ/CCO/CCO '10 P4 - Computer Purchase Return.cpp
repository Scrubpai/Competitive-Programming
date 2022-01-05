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

struct C {
    int c, v, t;
};
bool cmp(C a, C b) {
    return a.t < b.t;
}

int T, N, B, dp[6][3005]; vector<C> vec;

void solve(int tc) {

    cin >> T >> N;
    for (int i = 1, c, v, t; i <= N; i++) {
        cin >> c >> v >> t;
        vec.push_back({c, v, t});
    }
    sort(vec.begin(), vec.end(), cmp);
    cin >> B; int idx = 0;
    for (int i = 1; i <= T; i++) {
        while (idx < N && vec[idx].t <= i) {
            for (int j = B; j >= vec[idx].c; j--) dp[i][j] = max({dp[i][j], dp[i-1][j], dp[i-1][j-vec[idx].c] + vec[idx].v});
            idx++;
        }
    }
    if (dp[T][B] == 0) cout << -1 << nl;
    else cout << dp[T][B] << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);

    return 0;
}