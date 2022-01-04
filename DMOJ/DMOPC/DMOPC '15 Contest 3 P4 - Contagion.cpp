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

int n, X, q; ll adj[3005][3005], dis[3005], val; bool vis[3005]; pll a[3005];

void solve(int tc) {

    cin >> n;
    for (int i = 1; i <= n; i++) dis[i] = LL_INF;
    for (int i = 1; i <= n; i++) { ll x, y; cin >> x >> y; a[i] = {x, y}; }
    cin >> X; dis[X] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int x1 = a[i].first, y1 = a[i].second, x2 = a[j].first, y2 = a[j].second;
            adj[i][j] = adj[j][i] = (1LL * (x2 - x1) * (x2 - x1)) + (1LL * (y2 - y1) * (y2 - y1));
        }
    }
    for (int i = 1; i <= n; i++) {
        ll mn = LL_INF, idx = -1;
        for (int j = 1; j <= n; j++) {
            if (!vis[j] && dis[j] < mn) mn = dis[j], idx = j;
        }
        if (idx == -1) break;
        vis[idx] = 1;
        for (int j = 1; j <= n; j++) {
            if (!vis[j] && adj[idx][j] && dis[j] > dis[idx] + adj[idx][j]) dis[j] = dis[idx] + adj[idx][j];
        }
    }
    sort(dis + 1, dis + 1 + n);
    cin >> q;
    while (q--) {
        cin >> val;
        int pos = upper_bound(dis + 1, dis + 1 + n, val) - (dis + 1);
        cout << pos << nl;
    }

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tc = 1; //cin >> tc;
    for (int t = 0; t < tc; t++) solve(t);

    return 0;
}