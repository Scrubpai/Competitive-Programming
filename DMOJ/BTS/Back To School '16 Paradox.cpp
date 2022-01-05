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

int c; bool state; set<bool> st;

void solve() {

    cin >> c;
    while (c--) {
        int x; string str; cin >> x;
        if (x != 4) cin >> str;
        if (str == "false") state = false;
        else state = true;
        if (x == 1) {
            if (st.count(state)) cout << "false" << nl;
            else cout << "true" << nl;
            st.insert(state);
        } else if (x == 2) {
            if (st.count(state)) {
                cout << "true" << nl;
                st.erase(state);
            } else cout << "false" << nl;
        } else if (x == 3) {
            if (!st.count(state)) cout << -1 << nl;
            else cout << distance(st.begin(), st.find(state)) << nl;
        } else {
            if (st.count(true) && st.count(false)) cout << "false true\n";
            else if (st.count(true) && !st.count(false)) cout << "true\n";
            else if (!st.count(true) && st.count(false)) cout << "false\n";
            else cout << "\n";
        }
    }

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}