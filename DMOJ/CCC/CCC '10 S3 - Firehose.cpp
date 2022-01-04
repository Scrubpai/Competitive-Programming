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

const int MM = 1e6;
int h, k, a[1005], ans = INF;

bool check(int d) {
    int cnt = 0;
    for (int i = 0; i < h; i++) {
        int tmpi = i; cnt = 0;
        for (int j = i + 1; j < i + h; j++) {
            int cur = j % h;
            if (((a[cur] - a[tmpi] + MM) % MM) > d) {
                cnt++; tmpi = j;
            }
        }
        if (cnt + 1 <= k) return 1;
    }
    return 0;
}

void solve(int tc) {

    cin >> h;
    for (int i = 0; i < h; i++) cin >> a[i];
    sort(a, a + h);
    cin >> k; int lo = 0, hi = 2e6;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (check(mid)) ans = min(ans, mid), hi = mid - 1;
        else lo = mid + 1;
    }
    cout << ceil((double)ans / 2) << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tc = 1; //cin >> tc;
    for (int t = 0; t < tc; t++) solve(t);

    return 0;
}