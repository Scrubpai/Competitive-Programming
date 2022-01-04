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

const int MM = 1e6 + 5;
int N, Q, ans[MM]; pii a[MM];

void solve(int tc) {

    cin >> N;
    for (int i = 1, t, w; i <= N; i++) {
        cin >> t >> w;
        a[i] = {t, w};
    }
    sort(a + 1, a + 1 + N);
    int idx = 1;
    for (int i = 1; i <= MM - 5; i++) {
        ans[i] = ans[i-1];
        while (idx <= N && a[idx].first <= i) {
            ans[i] = max(ans[i], a[idx].second);
            idx++;
        }
    }
    cin >> Q;
    while (Q--) {
        int T; cin >> T;
        cout << ans[T] << nl;
    }

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);

    return 0;
}