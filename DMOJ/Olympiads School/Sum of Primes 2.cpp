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

const int MM = 1e5;
bool p[MM + 5]; int q, a, b, psa[MM + 5], tmp = 0; vector<int> arr;

void solve(int tc) {

    arr.push_back(-1);
    for (int i = 2; i <= MM; i++) {
        if (!p[i]) { tmp++; psa[tmp] = psa[tmp-1] + i, arr.push_back(i); }
        if (!p[i] && i <= sqrt(MM)) {
            for (int j = i * i; j <= MM; j += i) {
                p[j] = 1;
            }
        }
    }
    cin >> q;
    while (q--) {
        cin >> a >> b;
        int hi = upper_bound(arr.begin(), arr.end(), b) - arr.begin(); hi--;
        int lo = lower_bound(arr.begin(), arr.end(), a) - arr.begin();
        cout << psa[hi] - psa[lo-1] << nl;
    }

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tc = 1; //cin >> tc;
    for (int t = 0; t < tc; t++) solve(t);

    return 0;
}