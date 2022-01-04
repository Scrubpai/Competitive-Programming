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

int bit[1025][1025]; int tmp, S;

void update(int x, int y, int val) {
    for (int i = x; i <= S; i += i&-i) {
        for (int j = y; j <= S; j += j&-j) {
            bit[i][j] += val;
        }
    }
}

int query(int x, int y) {
    int sum = 0;
    for (int i = x; i >= 1; i -= i&-i) {
        for (int j = y; j >= 1; j -= j&-j) {
            sum += bit[i][j];
        }
    }
    return sum;
}

void solve(int tc) {

    cin >> tmp >> S;
    while (1) {
        cin >> tmp;
        if (tmp == 3) return;
        if (tmp == 1) {
            int x, y, a; cin >> x >> y >> a; x++; y++;
            update(x, y, a);
        } else if (tmp == 2) {
            int l, r, b, t; cin >> l >> b >> r >> t; l++; b++; r++; t++;
            cout << query(r, t) - query(r, b-1) - query(l-1, t) + query(l-1, b-1) << nl;
        }
    }

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tc = 1; //cin >> tc;
    for (int t = 0; t < tc; t++) solve(t);

    return 0;
}