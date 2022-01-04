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

const int MM = 2e5 + 5;
const int MX = 150000;
int n, v[MM], sum, bit[MM], v2[MM]; vector<int> val;

void update(int p) {
    for (int i = p; i <= MX; i += i&-i) {
        bit[i]++;
    }
}

ll query(int x) {
    ll ret = 0;
    for (int i = x; i >= 1; i -= i&-i) {
        ret += bit[i];
    }
    return ret;
}

void solve(int tc) {

    cin >> n; val.push_back(-INF); val.push_back(0);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        if (v[i] == 1) {
            sum++;
        } else {
            sum--;
        }
        v2[i] = sum; val.push_back(sum);
    }
    sort(val.begin(), val.end()); val.resize(unique(val.begin(), val.end()) - val.begin());
    int x = lower_bound(val.begin(), val.end(), 0) - val.begin(); update(x);
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        x = lower_bound(val.begin(), val.end(), v2[i]) - val.begin();
        update(x);
        ans += query(x-1);
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