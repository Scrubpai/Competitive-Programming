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
//#define sz(a) sizeof(a)/sizeof(a[0])
//#define AUT auto
//#define f first
//#define s second
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

int x, y, a[101][101];

void solve() {

    cin >> x >> y;
    int diff = y - x, tmp = 0, r = 1, c = 1;
    for (int i = 1; i; i++) {
        tmp += i;
        if (diff >= tmp) { r++; }
        else break;
        tmp += i;
        if (diff >= tmp) { c++; }
        else break;
    }
    int m = (int)ceil((double)r/2) -1 , n = (int)ceil((double)c/2) - 1;
    a[m][n] = x; tmp = 0;
    for (int i = x; i < y; ) {
        tmp++;
        for (int j = 1; j <= tmp && i < y; j++) {
            m++; i++; a[m][n] = i;
        }
        for (int j = 1; j <= tmp && i < y; j++) {
            n++; i++; a[m][n] = i;
        }
        tmp++;
        for (int j = 1; j <= tmp && i < y; j++) {
            m--; i++; a[m][n] = i;
        }
        for (int j = 1; j <= tmp && i < y; j++) {
            n--; i++; a[m][n] = i;
        }
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (a[i][j] == 0) cout << "   ";
            else if (a[i][j] <= 9) cout << " " << a[i][j] << " ";
            else cout << a[i][j] << " ";
        }
        cout << nl;
    }

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}