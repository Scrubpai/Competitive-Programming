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
#define rep(i,a,n) for (int i=a;i<n;i++)
#define rep1(i, a, n) for (int i=a; i<=n; i++)
#define per(i,a,n) for (int i=a-1;i>=n;i--)
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
//#define f first
//#define s second
#define nl '\n'
typedef unsigned long long ull;
const int MOD = 1e9 + 7;

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

const int MM = 3e6 + 5;
int n, k, a[MM]; deque<int> dqmin; deque<int> dqmax;

void pushmin(int x) {
    while (!dqmin.empty() && dqmin.back() > x) dqmin.pop_back();
    dqmin.push_back(x);
}
void pushmax(int x) {
    while (!dqmax.empty() && dqmax.back() < x) dqmax.pop_back();
    dqmax.push_back(x);
}

void solve() {

    cin >> n >> k; int lft = 1; ll ans = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i]; pushmin(a[i]); pushmax(a[i]);
        int mn = dqmin.front(), mx = dqmax.front();
        while (mx - mn > k) {
            if (a[lft] == dqmin.front()) dqmin.pop_front();
            if (a[lft] == dqmax.front()) dqmax.pop_front();
            mx = dqmax.front(); mn = dqmin.front();
            lft++;
        }
        ans += (i - lft + 1);
    }
    cout << ans << nl;

}

int32_t main() {
  //  ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}