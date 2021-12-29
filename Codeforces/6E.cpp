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
int n, k, h[MM], cnt; deque<int> mn, mx; vector<pii> res;

bool check(int a) {
    mn.clear(); mx.clear();
    for (int i = 1; i <= n; i++) {
        while (!mn.empty() && h[mn.back()] >= h[i]) mn.pop_back();
        while (!mx.empty() && h[mx.back()] <= h[i]) mx.pop_back();
        mn.push_back(i); mx.push_back(i);
        if (i > a) {
            if (mn.front() == i-a) mn.pop_front();
            if (mx.front() == i-a) mx.pop_front();
        }
        if (i >= a && h[mx.front()] - h[mn.front()] <= k) return 1;
    }
    return 0;
}

void solve(int tc) {

    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> h[i];
    int lo = 1, hi = n, ans = 1;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (check(mid)) { ans = max(ans, mid); lo = mid + 1; }
        else hi = mid - 1;
    }
    mn.clear(); mx.clear();
    for (int i = 1; i <= n; i++) {
        while (!mn.empty() && h[mn.back()] >= h[i]) mn.pop_back();
        while (!mx.empty() && h[mx.back()] <= h[i]) mx.pop_back();
        mn.push_back(i); mx.push_back(i);
        if (i > ans) {
            if (mn.front() == i-ans) mn.pop_front();
            if (mx.front() == i-ans) mx.pop_front();
        }
        if (i >= ans && h[mx.front()] - h[mn.front()] <= k) {
            cnt++; res.push_back({i - ans + 1, i});
        }
    }
    cout << ans << " " << cnt << nl;
    for (pii p : res) cout << p.first << " " << p.second << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tc = 1; //cin >> tc;
    for (int t = 0; t < tc; t++) solve(t);

    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
*/