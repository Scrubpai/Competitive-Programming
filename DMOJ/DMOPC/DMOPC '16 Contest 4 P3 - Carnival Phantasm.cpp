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

struct candy {
    int d, idx;
    bool operator < (const candy &other) const {
        if (this->d != other.d) return this->d < other.d;
        else return this->idx < other.idx;
    }
};

const int MM = 1e5 + 5;
int N, S, Q, d[MM]; set<int> flavour[MM]; set<candy> st[105];

void solve(int tc) {

    cin >> N >> S;
    for (int i = 1; i <= N; i++) cin >> d[i];
    for (int i = 1, s, a; i <= S; i++) {
        cin >> s >> a; st[a].insert({d[s], s});
        flavour[s].insert(a);
    }
    cin >> Q;
    while (Q--) {
        char ch; int x, k; cin >> ch;
        if (ch == 'A') {
            cin >> x >> k; flavour[x].insert(k);
            st[k].insert({d[x], x});
        } else if (ch == 'S') {
            cin >> x >> k; flavour[x].erase(k);
            st[k].erase({d[x], x});
        } else if (ch == 'E') {
            cin >> x >> k;
            for (int f : flavour[x]) { st[f].erase({d[x], x}); }
            flavour[x].clear(); d[x] = k;
        } else {
            cin >> k;
            if (st[k].empty()) cout << -1 << nl;
            else cout << st[k].begin()->idx << nl;
        }
    }

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tc = 1; //cin >> tc;
    for (int t = 0; t < tc; t++) solve(t);

    return 0;
}