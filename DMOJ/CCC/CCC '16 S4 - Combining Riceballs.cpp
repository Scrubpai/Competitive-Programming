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
//coordinate compression:sort(val.begin(), val.end());
//		val.resize(unique(val.begin(), val.end()) - val.begin());
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

int n, sz[405], psa[405]; bool dp[405][405];

void solve(int tc) {

    cin >> n; int ans = 0;
    for (int i = 1; i <= n; i++) {
        cin >> sz[i]; dp[i][i] = 1;
        psa[i] = psa[i-1] + sz[i];
        ans = max(ans, sz[i]);
    }
    for (int i = 1; i < n; i++) {
        if (sz[i] == sz[i+1]) {
            dp[i][i+1] =1 ;
            ans = max(ans, sz[i] * 2);
        }
    }
    for (int len = 3; len <= n; len++) {
        for (int i = 1; i + len - 1 <= n; i++) {
            int l = i, r = i + len - 1;
            for (int k = l + 1; k <= r; k++) {
                if (dp[l][k-1] && dp[k][r] && (psa[k-1] - psa[l-1] == psa[r] - psa[k-1])) dp[l][r] = 1;
            }
            int a = l, b = r;
            while (a <= b) {
                if (psa[a] - psa[l-1] > psa[r] - psa[b-1]) b--;
                else if (psa[a] - psa[l-1] < psa[r] - psa[b-1]) a++;
                else {
                    if (dp[l][a] && dp[a+1][b-1] && dp[b][r]) { dp[l][r] = 1; break; }
                    else { a++; b--; }
                }
            }
            if (dp[l][r]) ans = max(ans, psa[r] - psa[l-1]);
        }
    }
    cout << ans << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);

    return 0;
}