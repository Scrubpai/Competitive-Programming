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
int n, m, dsu[MM]; string str; vector<int> adj[MM];

int Find(int x) {
    if (dsu[x] == x) return x;
    else return dsu[x] = Find(dsu[x]);
}

void solve(int tc) {

    cin >> n >> m >> str; str = " " + str;
    for (int i = 1; i <= n; i++) dsu[i] = i;
    for (int i = 1, a, b; i < n; i++) {
        cin >> a >> b;
        if (str[a] == str[b]) {
            int fa = Find(a), fb = Find(b);
            if (fa != fb) {
                dsu[fa] = fb;
            }
        }
    }
    string ans = "";
    for (int i = 1; i <= m; i++) {
        int a, b; char ch; cin >> a >> b >> ch;
        int fa = Find(a), fb = Find(b);
        if (fa != fb) ans += '1';
        else {
            if (str[fa] == ch) ans += '1';
            else ans += '0';
        }
    }
    cout << ans << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tc = 1; //cin >> tc;
    for (int t = 0; t < tc; t++) solve(t);

    return 0;
}