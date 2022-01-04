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
#define INF 0x3f3f3f3f // for int
#define LL_INF 0x3f3f3f3f3f3f3f3f // for ll
#define gl(x) getline(cin, (x))
#define sz(x) (int)(x.size())
#define af(x) x.begin(), x.end()
#define ms(x, y) memset(x, y, sizeof(x))
#define lb lower_bound
#define ub upper_bound
#define mpp make_pair
#define pb push_back
#define nl '\n'
typedef unsigned long long ull;
const int MOD = 10;

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
string s; ll p[MM], hsh1[MM], hsh2[MM], base = 131; int n;

ll getSubstr(int l, int r) {
    return hsh1[r] - hsh1[l-1] * p[r-l+1];
}

void solve() {

    cin >> s; n = s.size(); p[0] = 1;
    for (int i = 1; i <= n; i++) p[i] = p[i-1] * base;
    for (int i = 1; i <= n; i++) {
        hsh1[i] = hsh1[i-1] * base + s[i-1];
        hsh2[i] = hsh2[i-1] * base + s[n-i];
    }
    for (int i = n - 1; i >= 1; i--) {
        if (hsh1[i] == hsh2[n] - hsh2[n-i] * p[i]) {
            for (int j = i + 1; j <= n; j++) {
                if (getSubstr(j - i + 1, j) == hsh1[i]) {
                    cout << i << nl; return;
                }
            }
        }
    }

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}