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

const int MM = 1e5 + 5;
int n, k, mx, b[MM], ans; vector<int> rem;

void solve(int tc) {

    cin >> n >> k;
    for (int i = 1; i <= n; i++) { cin >> b[i]; mx = max(mx, b[i]); }
    for (int i = 1; i <= mx; i++) {
        int cnt = 0; rem.clear();
        for (int j = 1; j <= n; j++) {
            cnt += (int)(b[j] / i);
            if (b[j] % i) rem.push_back(b[j] % i);
        }
        if (cnt < k / 2) break;
        if (cnt >= k) ans = max(ans, i * k / 2);
        else {
            sort(rem.rbegin(), rem.rend());
            int tmp = (cnt - k/2) * i, x = k - cnt, sz = rem.size();
            for (int j = 0; j < min(x, sz); j++) {
                tmp += rem[j];
            }
            ans = max(ans, tmp);
        }
    }
    cout << ans << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tc = 1; //cin >> tc;
    for (int t = 0; t < tc; t++) solve(t);

    return 0;
}