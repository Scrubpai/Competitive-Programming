#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<string> vs;
typedef complex<double> pnt;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define rep1(i, a, n) for (int i=a; i<=n; i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define per1(i,a,n) for (int i=a;i>=n;i--)
#define endl '\n'
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
#define f first
#define s second
#define nl '\n'
typedef unsigned long long ull;
const int MN = (int)1e5 + 5;
const int MOD = (int)1e9 + 7;

ll gcd(ll a, ll b){return b == 0 ? a : gcd(b, a % b);}
ll lcm(ll a, ll b){return a*b/gcd(a,b);}

vector<int> a; bool princess[MN]; bool kingdom[MN];

void solve() {

    int T; cin >> T;
    rep(t, 0, T) {
        int n; cin >> n;
        rep1(i, 1, n) { princess[i] = kingdom[i] = false; }
        rep1(i, 1, n) {
            int k; cin >> k; a.clear();
            rep(j, 0, k) { int x; cin >> x; a.pb(x); }
            rep(j, 0, k) {
                if (!kingdom[a[j]]) {
                    kingdom[a[j]] = true; princess[i] = true; break;
                }
            }
        }
        int a1 = -1, a2 = -1;
        rep1(i, 1, n) {
            if (!princess[i]) { a1 = i; break; }
        }
        if (a1==-1) { cout << "OPTIMAL" << nl; continue; }
        rep1(i, 1, n) {
            if (!kingdom[i]) { a2 = i; break; }
        }
        if (a2==-1) { cout << "OPTIMAL" << nl; continue; }
        cout << "IMPROVE" <<nl << a1 << " " << a2 << nl;
    }

}

int32_t main() {
   // ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}

