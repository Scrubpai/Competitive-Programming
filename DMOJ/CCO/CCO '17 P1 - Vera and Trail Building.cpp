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

int K; int cnt; vector<pii> ans;

void solve() {

    cin >> K;
    for (int sz = 5000; sz >= 2; sz--) {
        int paths = (sz * (sz - 1)) / 2;
        while (K >= paths) {
            int start = cnt + 1, last = cnt + sz;
            for (int i = start; i < last; i++) ans.push_back({i, i + 1});
            ans.push_back({last, start}); if (start != 1) ans.push_back({start, 1});
            K -= paths; cnt += sz;
        }
    }
    cout << cnt << " " << ans.size() << nl;
    for (pii p : ans ) cout << p.first << " " << p.second << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}