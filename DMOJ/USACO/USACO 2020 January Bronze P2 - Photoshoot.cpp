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

const int MM = 1e3 + 5;
int n, b[MM], ans[MM]; bool vis[MM];

void solve(int tc) {

    cin >> n;
    for (int i = 1; i < n; i++) cin >> b[i];
    for (int i = 1; i <= b[1] - 1; i++) {
        ans[1] = i; ms(vis, 0); vis[i] = 1; bool flag = 0;
        for (int j = 2; j <= n; j++) {
            ans[j] = b[j-1] - ans[j-1];
            if (ans[j] > n || ans[j] < 1 || vis[ans[j]]) { flag = 1; break; }
            vis[ans[j]] = 1;
        }
        if (!flag) {
            for (int j = 1; j <= n; j++) {
                cout << ans[j] << " ";
            }
            cout << nl;
            return;
        }
    }

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tc = 1; //cin >> tc;
    for (int t = 0; t < tc; t++) solve(t);

    return 0;
}