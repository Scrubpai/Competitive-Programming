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
const int MOD = 1000000000;

ll gcd(ll a, ll b){return b == 0 ? a : gcd(b, a % b);}
ll lcm(ll a, ll b){return a*b/gcd(a,b);}
ll pwmd(ll b, ll exp) {
    ll ret = 1;
    while (exp>0) {
        if (exp%2==1) ret = (ret*b)%MOD;
        exp/=2;
        b = (b*b)%MOD;
    }
    return ret;
}

const int MM = 1e5 + 5;
int g, p; vector<int> a;

int binarySearch(int lo, int hi, int val) {
    int idx = -1;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (a[mid] > val) hi = mid - 1;
        else { idx = max(idx, mid); lo = mid + 1;}
    }
    return idx;
}

void solve() {

    cin >> g >> p;
    for (int i = 1; i <= g; i++) a.push_back(i);
    for (int i = 1; i <= p; i++) {
        int val; cin >> val;
        int pos = binarySearch(0, a.size() - 1, val);
        if (pos == -1) { cout << i - 1 << nl; return; }
        else a.erase(a.begin() + pos);
    }
    cout << p << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}