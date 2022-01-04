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

const int MM = 1e6 + 5;
int N; ll a[MM], P, bit[MM + 5]; vector<ll> val;

ll query(int p) {
    ll ret = 0;
    for (; p >= 1; p -= p&-p) ret += bit[p];
    return ret;
}

void update(int p) {
    for (; p <= MM - 5; p += p&-p) bit[p]++;
}

void solve(int tc) {

    cin >> N; ll sum = 0; val.push_back(-LL_INF); val.push_back(0);
    for (ll i = 1; i <= N; i++) {
        cin >> a[i];
    }
    cin >> P;
    for (int i = 1; i <= N; i++) {
        sum += a[i];
        val.push_back(sum - 1LL * P * i);
    }
    sort(val.begin(), val.end()); val.resize(unique(val.begin(), val.end()) - val.begin());
    ll tmp = lower_bound(val.begin(), val.end(), 0) - val.begin(); update(tmp);
    sum = 0;
    ll ans = 0;
    for (int i = 1; i <= N; i++) {
        sum += a[i];
        ll cur = sum - 1LL * P * i;
        cur = lower_bound(val.begin(), val.end(), cur) - val.begin();
        ans += query(cur);
        update(cur);
    }
    cout << ans << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tc = 1;// cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);

    return 0;
}