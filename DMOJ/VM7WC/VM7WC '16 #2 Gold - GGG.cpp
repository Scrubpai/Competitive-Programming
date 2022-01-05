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
#define f first
#define s second
#define nl '\n'
typedef unsigned long long ull;
const int MN = (int)1e6 + 5;
const int MOD = (int)1e9 + 7;

//remember to remove ios stuff if i use scanf LOL

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

int n1, n2; int a1[MN], a2[MN]; int seq[MN]; int mp[MN]; vector<int> dp;

void solve() {

    cin >> n1; ms(mp, -1);
    for (int i=1; i<=n1; i++) { cin >> a1[i]; mp[a1[i]] = i; }
    cin >> n2; int idx = 1;
    for (int i=1; i<=n2; i++) {
        cin >> a2[i];
        if (mp[a2[i]]!=-1) {
            seq[idx++] = mp[a2[i]];
        }
    }

    for (int i=1; i<idx; i++) {
        if (dp.empty() || seq[i] > dp[dp.size()-1]) { dp.push_back(seq[i]); }
        else {
            int id = lower_bound(dp.begin(), dp.end(), seq[i]) - dp.begin();
            dp[id] = seq[i];
        }
    }

    cout << dp.size() << nl;

}

int32_t main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}