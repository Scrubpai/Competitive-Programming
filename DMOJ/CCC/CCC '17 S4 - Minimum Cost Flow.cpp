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

struct E {
    ll u, v, w, idx;
};
bool cmp(E a, E b) {
    if (a.w != b.w) return a.w < b.w;
    else return a.idx < b.idx;
}

const int MM = 1e5 + 5;
ll n, m, D, dsu[MM]; vector<E> edges;

int Find(int x) {
    if (dsu[x] == x) return x;
    else return dsu[x] = Find(dsu[x]);
}

void solve(int tc) {

    cin >> n >> m >> D;
    for (int i = 1; i <= n; i++) dsu[i] = i;
    for (ll i = 1, a, b, c; i <= m; i++) {
        cin >> a >> b >> c;
        edges.push_back({a, b, c, i});
    }
    sort(edges.begin(), edges.end(), cmp);
    ll mx = 0, ans = 0, cnt = 0, idx = -1;
    for (E e : edges) {
        int fu = Find(e.u), fv = Find(e.v);
        if (fu != fv) {
            dsu[fu] = fv; idx = e.idx; cnt++;
            if (e.idx > n - 1) ans++;
            mx = max(mx, e.w);
        }
        if (cnt == n - 1) break;
    }
    for (int i = 1; i <= n; i++) dsu[i] = i;
    if (idx > n - 1) {
        for (E e : edges) {
            int fu = Find(e.u), fv = Find(e.v);
            if (fu != fv) {
                if (e.w < mx || (e.w == mx && e.idx <= n - 1)) dsu[fu] = fv;
                else if (e.idx <= n - 1 && e.w <= D) { cout << ans - 1 << nl; return; }
            }
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