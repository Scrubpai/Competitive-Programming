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

const int MM = 500005;
int n, cards[MM], A = 1, B = 1, cnt, psa[MM]; vector<int> adj[2 * MM];

void solve() {

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> cards[i]; if (cards[i] == i) psa[i] = 1;
        adj[cards[i] + i].push_back(i);
        psa[i] += psa[i-1];
    }
    for (int i = 2; i <= 2 * n; i++) sort(adj[i].begin(), adj[i].end());
    cnt = psa[n]; int cur = 0;
    for (int i = 1; i <= n; i++) {
        int lft = i, rit = cards[i]; if (lft > rit) swap(lft, rit);
        int val = (upper_bound(adj[lft + rit].begin(), adj[lft + rit].end(), rit)) - adj[lft + rit].begin() - (lower_bound(adj[lft + rit].begin(), adj[lft + rit].end(), lft) - adj[lft + rit].begin());
        cur = psa[lft - 1] + psa[n] - psa[rit] + val;
        if (cur > cnt) {
            cnt = cur; A = lft; B = rit;
        }
    }
    cout << cards[A] << " " << cards[B] << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}