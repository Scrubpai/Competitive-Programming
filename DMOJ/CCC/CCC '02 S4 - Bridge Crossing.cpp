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
#define gl(x) getline(cin, (x))
#define sz(x) (int)(x.size())
#define af(x) x.begin(), x.end()
#define ms(x, y) memset(x, y, sizeof(x))
#define mpp make_pair
#define pb push_back
#define AUT auto
#define nl '\n'
typedef unsigned long long ull;
const int MOD = 1e9 + 7;
const lld pi = 3.14159265358979323846;

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

int m, q, dp[105], pre[105], times[105]; string names[105]; stack<int> st;

void solve(int tc) {

    cin >> m >> q; ms(dp, INF); dp[0] = 0;
    for (int i = 1; i <= q; i++) cin >> names[i] >> times[i];
    for (int i = 1; i <= q; i++) {
        int mx = times[i];
        for (int j = i; j >= max(i - m + 1, 1); j--) {
            mx = max(mx, times[j]);
            if (dp[i] > mx + dp[j-1]) {
                dp[i] = mx + dp[j-1]; pre[i] = j - 1;
            }
        }
    }
    cout << "Total Time: " << dp[q] << nl;
    for (int i = q; i != 0; i = pre[i]) st.push(i);
    int i = 1;
    while (i <= q) {
        cout << names[i] << " ";
        if (i == st.top()) { st.pop(); cout << nl; }
        i++;
    }

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tc = 1; //cin >> tc;
    for (int t = 0; t < tc; t++) solve(t);

    return 0;
}