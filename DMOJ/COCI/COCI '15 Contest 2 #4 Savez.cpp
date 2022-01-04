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

int N; string str; unordered_map<ll, ll> mp; ll base = 131;

void solve(int tc) {

    cin >> N; ll ans = 0;
    for (int i = 1; i <= N; i++) {
        cin >> str;
        ll m = str.size(), mx = 1; ll pre = 0, suf = 0, p = 1;
        for (int j = 0; j < m; j++) {
            pre = pre * base + str[j]; suf = str[str.size() - j - 1] * p + suf; p *= base;
            if (pre == suf) {
                mx = max(mx, mp[pre] + 1);
            }
        }
        mp[pre] = mx;
        ans = max(ans, mx);
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