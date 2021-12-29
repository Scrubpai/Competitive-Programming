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

const int MM = 2e5 + 5;
int n; string str;

void solve(int tc) {

    cin >> n >> str; int L = 0, R = 0, idx = -1;
    for (int i = 0; i < n; i++) {
        if (str[i] == 'L') L++;
        else R++;
        if (str[0] != str[i] && idx == -1) idx = i;
    }
    if (L == n || R == n) { cout << ceil((double)n / 3) << nl; return; }
    L = 0; R = 0; int ans = 0;
    for (int i = idx; i < n + idx; i++) {
        int cur = i % n;
        if (str[cur] == 'L') {
            L++;
            ans += (int)(R / 3);
            R = 0;
        } else {
            R++;
            ans += (int)(L / 3);
            L = 0;
        }
    }
    ans += (int)(L / 3); ans += (int)(R / 3);
    cout << ans << nl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tc = 1; cin >> tc;
    for (int t = 0; t < tc; t++) solve(t);

    return 0;
}