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
//coordinate compression:sort(val.begin(), val.end());
//		val.resize(unique(val.begin(), val.end()) - val.begin());
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

const int MM = 1e5; //cnt for # of groups in sqrt decomp
int n, v, ans = 1, rem, cnt; bool pSmall[MM+5], pLarge[MM+5], alive[MM+5]; vector<int> adj[MM];

void sieve() {
    pSmall[1] = 1;
    for (ll i = 2; i * i <= MM; i++) {
        if (!pSmall[i]) {
            for (ll j = i * i; j <= MM; j += i) pSmall[j] = 1;
        }
    }
    for (int i = 1; i <= MM; i++) {
        if (1LL * i * i <= MM) continue;
        pLarge[i] = pSmall[i];
    }
}

int kill(int m) {
    int ret = 0;
    for (int i = m; i <= n; i += m) {
        if (alive[i]) {
            rem--; alive[i] = 0;
            ret++;
        }
    }
    return ret;
}

void init() {
    vector<int> primes;
    for (ll i = sqrt(MM); i <= MM; i++) {
        if (pLarge[i]) continue;
        if (i > n) break;
        primes.push_back(i);
        if (primes.size() >= 100) {
            cnt++;
            adj[cnt] = primes; primes.clear();
        }
    }
    if (!primes.empty()) {
        cnt++;
        adj[cnt] = primes;
    }
}

void solve(int tc) {

    cin >> n; sieve(); ms(alive, 1); rem = n;
    for (ll i = 1; i * i <= MM; i++) {
        if (i > n) break;
        if (!pSmall[i]) {
            cout << "B " << i << endl;
            cin >> v;
            kill(i);
        }
    }
    cout << "A " << 1 << endl;
    cin >> v;
    if (v != rem) {
        //x has a factor that is less than sqrt(MM)
        for (ll i = 1; i <= n; i++) {
            if (i * i <= 1LL * MM) {
                if (pSmall[i]) continue;
                ll prev = 1, prod = i;
                while (1) {
                    cout << "A " << prod << endl;
                    cin >> v;
                    if (v == 0) break;
                    prev = prod; prod *= i;
                    if (prod > n) break;
                }
                ans *= prev;
            } else {
                if (pLarge[i]) continue;
                cout << "B " << i << endl;
                cin >> v;
                int tmp = kill(i);
                if (tmp != v) {
                    ans *= i; break;
                }
            }
        }
    } else {
        //x is a big prime
        init();
        for (int i = 1; i <= cnt; i++) {
            for (int p : adj[i]) {
                cout << "B " << p << endl;
                cin >> v;
                kill(p);
            }
            cout << "A " << 1 << endl;
            cin >> v;
            if (v != rem) {
                for (int p : adj[i]) {
                    cout << "A " << p << endl;
                    cin >> v;
                    if (v == 1) { cout << "C " << p << endl; return; }
                }
            }
        }
    }
    cout << "C " << ans << endl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tc = 1;// cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);

    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
*/