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
int n, k; stack<int> st; bool emp[MM]; int student[MM];

void solve() {

    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        int p; cin >> p; emp[p] = 1;
    }
    for (int i = 1; i <= k + 1; i++) {
        int p; cin >> p;
        if (emp[p]) emp[p] = 0;
        else student[p] = i;
    }
    for (int t = 0; t < 2; t++) {
        for (int i = 1; i <= n; i++) {
            if (student[i]) { st.push(student[i]); student[i] = 0; }
            if (emp[i] && !st.empty()) { st.pop(); emp[i] = 0; }
        }
    }
    cout << st.top() << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}