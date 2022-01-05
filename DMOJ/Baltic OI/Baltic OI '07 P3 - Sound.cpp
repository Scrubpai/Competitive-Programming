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

const int MM = 1000005;
int n, m, c, a[MM]; deque<int> dqmin, dqmax;

void pushmin(int x) {
    while (!dqmin.empty() && dqmin.back() > x) dqmin.pop_back();
    dqmin.push_back(x);
}
void pushmax(int x) {
    while (!dqmax.empty() && dqmax.back() < x) dqmax.pop_back();
    dqmax.push_back(x);
}

void solve() {

    cin >> n >> m >> c; int cnt = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pushmin(a[i]); pushmax(a[i]);
        if (i >= m) {
            if (dqmax.front() - dqmin.front() <= c)  { cout << i - m + 1 << nl; cnt++; }
            if (dqmin.front() == a[i - m + 1]) dqmin.pop_front();
            if (dqmax.front() == a[i - m + 1]) dqmax.pop_front();
        }
    }
    if (cnt == 0) cout << "NONE" << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}