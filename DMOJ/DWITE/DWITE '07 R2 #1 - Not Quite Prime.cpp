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

int T = 5, N; bool p[1005];

void sieve() {
    p[1] = 1;
    for (int i = 2; i <= 1000; i++) {
        if (!p[i]) {
            for (int j = i * i; j <= 1000; j += i) {
                p[j] = 1;
            }
        }
    }
}

void solve(int tc) {

    sieve();
    while (T--) {
        cin >> N; bool flag = 0;
        for (int i = 2; i <= sqrt(N); i++) {
            if (N % i == 0) {
                if (!p[i] && !p[N / i]) {
                    flag = 1; break;
                }
            }
        }
        if (flag) cout << "semiprime" << nl;
        else cout << "not" << nl;
    }

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tc = 1; //cin >> tc;
    for (int t = 0; t < tc; t++) solve(t);

    return 0;
}