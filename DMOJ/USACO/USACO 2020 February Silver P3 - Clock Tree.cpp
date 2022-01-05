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
const int MOD = 1000000000;

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

int n, t[2505], tmp[2505]; vector<int> adj[2505]; bool go[2505];

void dfs(int cur, int pa) {
    for (int v : adj[cur]) {
        if (v != pa) {
            tmp[v]++;
            dfs(v, cur);
            tmp[cur] = (tmp[cur] + (12 - tmp[v])) % 12;
        }
    }
    tmp[pa]++;
}

void solve(int tc) {

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> t[i];
        t[i] %= 12;
    }
    for (int i = 1, a, b; i < n; i++) {
        cin >> a >> b;
        adj[a].push_back(b); adj[b].push_back(a);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) tmp[j] = t[j];
        dfs(i, 0);
        if (tmp[i] == 0 || tmp[i] == 1) {
            ans++;
        }
    }
    cout << ans << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);

    return 0;
}