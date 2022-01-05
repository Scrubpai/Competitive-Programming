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

int n, q; ll bit[255][255][255], len[255][255][255], ans; char ch;

void update(int x, int y, int z, ll v) {
    for (int i = x; i <= n; i += i&-i) {
        for (int j = y; j <= n; j += j&-j) {
            for (int k = z; k <= n; k += k&-k) {
                bit[i][j][k] += v;
            }
        }
    }
}

ll query(int x, int y, int z) {
    ll ret = 0;
    for (int i = x; i >= 1; i -= i&-i) {
        for (int j = y; j >= 1; j -= j&-j) {
            for (int k = z; k >= 1; k -= k&-k) {
                ret += bit[i][j][k];
            }
        }
    }
    return ret;
}

ll getVal(int x1, int y1, int z1, int x2, int y2, int z2) {
    return query(x2, y2, z2) - query(x1 - 1, y2, z2) - query(x2, y1 - 1, z2) - query(x2, y2, z1 - 1) + query(x1-1, y1-1, z2) + query(x2, y1-1, z1-1) + query(x1-1, y2, z1-1) - query(x1-1, y1-1, z1-1);
}

void solve(int tc) {

    cin >> n >> q;
    while (q--) {
        cin >> ch;
        if (ch == 'C') {
            int x, y, z, L; cin >> x >> y >> z >> L;
            update(x, y, z, -len[x][y][z]);
            update(x, y, z, L);
            len[x][y][z] = L;
        } else {
            int x1, x2, y1, y2, z1, z2; cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
            ans += getVal(x1, y1, z1, x2, y2, z2);
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