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

struct Q {
    ll l, r, k, idx;
};

bool cmp(Q a, Q b) {
    return a.k < b.k;
}

const int MM = 2e5 + 5;
int N, q; pll a[MM]; ll bit[MM], psa[MM], ans[MM]; vector<Q> queries;

void update(int j, ll v) {
    for (int i = j; i <= N; i += i&-i) {
        bit[i] += v;
    }
}

ll query(int j) {
    ll sum = 0;
    for (int i = j; i >= 1; i -= i&-i) {
        sum += bit[i];
    }
    return sum;
}

void solve(int tc) {

    cin >> N >> q;
    for (int i = 1; i <= N; i++) {
        ll v; cin >> v; psa[i] = psa[i-1] + v;
        a[i] = {v, i};
    }
    sort(a + 1, a + 1 + N);
    for (int i = 1; i <= q; i++) {
        ll l, r, k; cin >> l >> r >> k;
        queries.push_back({l, r, k, i});
    }
    sort(queries.begin(), queries.end(), cmp); int idx = 1;
    for (int i = 0; i < q; i++) {
        Q cur = queries[i];
        while (idx <= N && a[idx].first < cur.k) { update(a[idx].second, a[idx].first); idx++; }
        int l = cur.l, r = cur.r;
        ll less = query(r) - query(l-1), greater = (psa[r] - psa[l-1]) - less;
        ans[cur.idx] = greater - less;
    }
    for (int i = 1; i <= q; i++) cout << ans[i] << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tc = 1; //cin >> tc;
    for (int t = 0; t < tc; t++) solve(t);

    return 0;
}