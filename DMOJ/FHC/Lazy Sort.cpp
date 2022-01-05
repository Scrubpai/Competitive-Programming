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

//remember to remove ios stuff if i use scanf LOL

//printf("%05lld\n", x); --> print last 5 digits including 0's
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

int T, n;deque<int> a;

bool fun(deque<int> a, int pos) {
    deque<int> dest;
    if (pos == 0) { dest.push_back(a.front()); a.pop_front(); }
    else { dest.push_back(a.back()); a.pop_back(); }
    while (!a.empty()) {
        if (a.front() == dest.front() - 1) { dest.push_front(a.front()); a.pop_front(); }
        else if (a.front() == dest.back() + 1) { dest.push_back(a.front()); a.pop_front(); }
        else if (a.back() == dest.front() - 1) { dest.push_front(a.back()); a.pop_back(); }
        else if (a.back() == dest.back() + 1) { dest.push_back(a.back()); a.pop_back(); }
        else return false;
    }
    return true; 
}

void solve() {

    cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> n; a.clear();
        for (int i = 1; i <= n; i++) {
            int x; cin >> x; a.push_back(x);
        }
        cout << "Case #" << t << ": ";
        if (fun(a, 0) || fun(a, 1)) cout << "yes" << nl;
        else cout << "no" << nl;
    }

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}