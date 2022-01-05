//why tle lol
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
const int MOD = 1e9 + 7;

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

int D, w[1005], T, F, ans[1005], wait[1005]; vector<int> adj[1005];

void solve(int tc) {

    cin >> D;
    for (int i = 1; i <= D; i++) { cin >> w[i]; w[i]--; }
    cin >> F;
    for (int i = 1, u, v; i <= F; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
    }
    cin >> T; ms(wait, -1);
    ans[1] = 1;
    for (int v : adj[1]) wait[v] = w[v];
    for (int i = 1; i <= T; i++) {
        for (int j = 1; j <= D; j++) {
            if (wait[j] == -1) continue;
            if (i > wait[j]) {
                ans[j]++; 
                for (int nxt : adj[j]) {
                    if (wait[nxt] == -1) wait[nxt] = i + w[nxt];
                }
            }
        }
        for (int j = 1; j <= D; j++) {
            if (wait[j] == -1) continue;
            if (i > wait[j]) wait[j] = -1;
        }
    }
    for (int i = 1; i <= D; i++) cout << ans[i] << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);

    return 0;
}