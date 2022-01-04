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
const int MXN = 1e6 + 5;

struct interval {
    int l, r;
};
bool cmp(interval a, interval b) {
    if (a.l != b.l) return a.l > b.l;
    else return a.r < b.r;
}

int n, dp[MM], pre[MM], bit[MXN]; interval arr[MM];

void update(int idx, int v) {
    for (int i = idx; i <= MXN - 5; i += i&-i) {
        if (dp[bit[i]] < dp[v]) {
            bit[i] = v;
        }
    }
}

int query(int idx) {
    int ret = 0, mx = 0;
    for (int i = idx; i >= 1; i -= i&-i) {
        if (dp[bit[i]] > mx) {
            mx = dp[bit[i]]; ret = bit[i];
        }
    }
    return ret;
}

void solve(int tc) {

    cin >> n;
    for (int i = 1, l, r; i <= n; i++) {
        cin >> l >> r;
        arr[i] = {l, r};
    }
    sort(arr + 1, arr + 1 + n, cmp);
    int mx = 0, st = 0;
    for (int i = 1; i <= n; i++) {
        int last = query(arr[i].r);
        dp[i] = dp[last] + 1; pre[i] = last; update(arr[i].r, i);
        if (dp[i] > mx) {
            mx = dp[i]; st = i;
        }
    }
    cout << mx << nl;
    for (int i = st; i != 0; i = pre[i]) {
        cout << arr[i].l << " " << arr[i].r << nl;
    }

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tc = 1; //cin >> tc;
    for (int t = 0; t < tc; t++) solve(t);

    return 0;
}