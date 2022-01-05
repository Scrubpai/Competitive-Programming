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

const int MM = 1e5 + 5;
int n, m, f[MM], s[MM], ans[MM], idx[MM]; bool flag;

void rec(int i, int cereal) {
    if (s[i] == cereal) return;
    else {
        if (idx[s[i]] != -1 && idx[s[i]] < i) return;
        else if (idx[s[i]] == -1) { flag = 1; idx[s[i]] = i; }
        else if (idx[s[i]] > i) {
            rec(idx[s[i]], s[i]);
            idx[s[i]] = i;
        }
    }
}

void solve(int tc) {

    cin >> n >> m; ms(idx, -1);
    for (int i = 1; i <= n; i++) {
        cin >> f[i] >> s[i];
    }
    for (int i = n; i >= 1; i--) {
        if (idx[f[i]] == -1) {
            idx[f[i]] = i; ans[i] = ans[i+1] + 1;
            continue;
        }
        flag = 0;
        rec(idx[f[i]], f[i]);
        idx[f[i]] = i;
        if (flag) ans[i] = ans[i+1] + 1;
        else ans[i] = ans[i+1];
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);

    return 0;
}