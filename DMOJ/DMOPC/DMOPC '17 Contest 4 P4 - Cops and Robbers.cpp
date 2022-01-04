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

const int MM = 1e6 + 5;
int N, a[MM]; int cnt, ans[MM], idx[MM]; set<int> st; int cop[MM]; vector<int> rem;

void solve() {

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> cop[i];
        if (!st.count(cop[i])) { st.insert(cop[i]); a[cnt] = cop[i]; idx[cop[i]] = cnt++; }
    }
    for (int i = 1; i <= N; i++) {
        if (!st.count(i)) rem.push_back(i);
    }
    if (cnt == 1) { cout << -1 << nl; return; }
    int cur = 0;
    for (int i = 1; i <= N; i++) {
        if (st.count(cop[i])) {
            st.erase(cop[i]);
            ans[i] = a[((idx[cop[i]] - 1 + cnt) % cnt)];
        }
    }
    for (int i = 1; i <= N; i++) {
        if (ans[i] == 0) ans[i] = rem[cur++];
        cout << ans[i] << " ";
    }

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}