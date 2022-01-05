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
#define mpp make_pair
#define pb push_back
#define AUT auto
#define nl '\n'
typedef unsigned long long ull;
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

int n, m, t; vector<pii> vec; map<ll, int> mp; ll ans = 1e18;

void solve() {

    cin >> n >> m >> t; mp[0] = n;
    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        vec.push_back({x, y});
    }
    sort(vec.begin(), vec.end());
    for (pii cur : vec) {
        auto it = mp.upper_bound((ll)cur.first);
        if (it != mp.begin()) it--;
        if (it-> first + t <= cur.first) {
            ans = min(ans, it->first);
        }
        ll st = max((ll)cur.first, it->first), ed = st + cur.second;
        it-> second--;
        if (it->second == 0) mp.erase(it);
        mp[ed]++;
    }
    cout << min(ans, mp.begin()->first) << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}