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

const int MM = 1e5 + 5;
ll n, m, bit[MM], freq[MM], a[MM];

void update(int idx, ll v, ll tree[]) {
    for (int i = idx; i <= MM - 5; i += i&-i) {
        tree[i] += v;
    }
}

ll query(int idx, ll tree[]) {
    ll sum = 0;
    for (int i = idx; i > 0; i -= i&-i) {
        sum += tree[i];
    }
    return sum;
}

void solve(int tc) {

    cin >> n >> m;
    for (int i = 1, x; i <= n; i++) {
        cin >> x; a[i] = x;
        update(i, x, bit); update(x, 1, freq);
    }
    for (int i = 1; i <= m; i++) {
        char ch; cin >> ch;
        if (ch == 'C') {
            ll x, v; cin >> x >> v;
            update(x, v - a[x], bit); update(a[x], -1, freq); update(v, 1, freq); a[x] = v;
        } else if (ch == 'S') {
            int l, r; cin >> l >> r;
            cout << query(r, bit) - query(l - 1, bit) << nl;
        } else {
            ll v; cin >> v;
            cout << query(v, freq) << nl;
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