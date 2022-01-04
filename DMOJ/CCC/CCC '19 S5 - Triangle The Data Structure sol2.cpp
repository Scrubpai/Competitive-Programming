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

int n, k; ll bit[3005][3005], triangle[3005][3005]; ll ans;

void update(int r, int c, ll v) {
    for (int i = r; i <= n; i += i&-i) {
        for (int j = c; j <= n; j += j&-j) {
            bit[i][j] = max(bit[i][j], v);
        }
    }
}

ll query(int r, int c) {
    ll ret = 0;
    for (int i = r; i >= 1; i -= i&-i) {
        for (int j = c; j >= 1; j -= j&-j) {
            ret = max(ret, bit[i][j]);
        }
    }
    return ret;
}

void solve(int tc) {

    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = n - i + 1; j <= n; j++) {
            cin >> triangle[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        int tmp = n;
        for (int j = n - i + 1; j <= n; j++) {
            update(tmp, j, triangle[tmp][j]);
            if (n - tmp + 1 >= k) {
                ans += query(tmp + k - 1, j);
            }
            tmp--;
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