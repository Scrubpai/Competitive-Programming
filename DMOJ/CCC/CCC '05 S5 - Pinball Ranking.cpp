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

const int MM = 1e5 + 5;
ll t, bit[MM], a[MM], tmp, ans; vector<int> val; unordered_map<int, int> mp;

void update(int idx) {
    for (int i = idx; i <= tmp; i += i&-i) {
        bit[i]++;
    }
}

ll query(int idx) {
    ll sum = 0;
    for (int i = idx; i >= 1; i -= i&-i) {
        sum += bit[i];
    }
    return sum;
}

void solve(int tc) {

    cin >> t;
    for (int i = 1; i <= t; i++) { cin >> a[i]; val.push_back(a[i]); }
    sort(val.begin(), val.end()); tmp = 1;
    for (int x : val) {
        if (mp[x] == 0) {
            tmp++; mp[x] = tmp;
        }
    }
    for (int i = 1; i <= t; i++) {
        int cur = mp[a[i]];
        ans += (i - query(cur)); update(cur);
    }
    double newans = (double)ans / t;
    printf("%.2f\n", newans);

}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tc = 1; //cin >> tc;
    for (int t = 0; t < tc; t++) solve(t);

    return 0;
}