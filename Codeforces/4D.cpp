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

const int MM = 1e6 + 5;

struct C {
    int w, h, id;
};
bool cmp(C a, C b) {
    return a.w < b.w;
}

int n, w, h, wid[5005], hei[5005], dp[5005], pre[5005], idx = 0; C a[5005];

void solve(int tc) {

    cin >> n >> w >> h;
    for (int i = 1; i <= n; i++) {
        cin >> wid[i] >> hei[i];
        if (wid[i] > w && hei[i] > h) {
            idx++; a[idx] = {wid[i], hei[i], i};
        }
    }
    if (idx == 0) { cout << 0 << nl; return; }
    sort(a + 1, a + 1 + idx, cmp);
    int mx = 0, st = 0;
    for (int i = 1; i <= idx; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (wid[a[i].id] > wid[a[j].id] && hei[a[i].id] > hei[a[j].id] && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1; pre[i] = j;
            }
        }
        if (dp[i] > mx) { mx = dp[i]; st = i; }
    }
    cout << mx << nl; vector<int> arr;
    for (int i = st; i != 0; i = pre[i]) arr.push_back(i);
    reverse(arr.begin(), arr.end());
    for (int x : arr) cout << a[x].id << " ";


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