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

const int MM = 1e5 + 5;

struct T {
    ll q; int a, b, i;
};
bool cmp(T a, T b) {
    return a.q < b.q;
}

int N, Q; ll bit[MM], q, M; ll ans[MM], psa[MM]; vector<T> a; vector<pii> mass;

ll query(int p) {
    ll sum = 0;
    for (int i = p; i >= 1; i -= i&-i) sum += bit[i];
    return sum;
}

void update(int p, ll x) {
    for (int i = p; i <= N; i += i&-i) bit[i] += x;
}

void solve(int tc) {

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> M;
        psa[i] = psa[i-1] + M;
        mass.push_back({M, i});
    }
    cin >> Q;
    for (int i = 1; i <= Q; i++) {
        int l, r; cin >> l >> r >> q; l++; r++;
        a.push_back({q, l, r, i});
    }
    sort(mass.begin(), mass.end()); sort(a.begin(), a.end(), cmp);
    int top = 0;
    for (int i = 0; i < Q; i++) {
        while (top < N && a[i].q > mass[top].first) { update(mass[top].second, mass[top].first); top++; }
        int j = a[i].i;
        ans[j] = (psa[a[i].b] - psa[a[i].a - 1]) - (query(a[i].b) - query(a[i].a-1));
    }
    for (int i = 1; i <= Q; i++) cout << ans[i] << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);

    return 0;
}