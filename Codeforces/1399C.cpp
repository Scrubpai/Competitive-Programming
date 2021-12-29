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

int T, n, a[51], freq[101];

void solve() {

    cin >> T;
    while (T--) {
        cin >> n; int teams = 0, weight = 0;
        for (int i = 1; i <= 2 * n; i++) freq[i] = 0;
        for (int i = 1; i <= n; i++) { cin >> a[i]; freq[a[i]]++; }
        for (int sum = 2 * n; sum >= 2; sum--) {
            int cnt = 0;
            for (int i = 1; i <= sum / 2; i++) {
                if (sum - i > n) continue;
                if (i != sum - i) cnt += min(freq[i], freq[sum - i]);
                else cnt += (freq[i] / 2);
            }
            if (cnt > teams) { teams = cnt; }
        }
        cout << teams << nl;
    }

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}