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

struct planet {
    int a, b, idx;
};
bool cmp(planet x, planet y) {
    return x.b < y.b;
}

const int MM = 1e5 + 5;
int n, p, fuel, cnt; planet arr[MM];

void solve(int tc) {

    cin >> n >> p;
    for (int i = 1; i <= n; i++) {
        int a, b; cin >> a >> b;
        arr[i] = {a, b, i};
    }
    fuel = arr[p].a; cnt = 1; sort(arr + 1, arr + 1 + n, cmp);
    for (int i = 1; i <= n; i++) {
        if (arr[i].idx == p) continue;
        if (fuel < arr[i].b) break;
        if (arr[i].a - arr[i].b >= 0) {
            fuel += arr[i].a - arr[i].b; cnt++;
        }
    }
    cout << fuel << nl << cnt << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tc = 1; //cin >> tc;
    for (int t = 0; t < tc; t++) solve(t);

    return 0;
}