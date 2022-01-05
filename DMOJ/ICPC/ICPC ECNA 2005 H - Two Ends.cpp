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
#define f first
#define s second
#define nl '\n'
typedef unsigned long long ull;
const int MN = 1e6 + 5;
const int MOD = 100000;

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

int n, dp[1001][1001], a[1001];

int fun(int lft, int rit, int move) {
    if (lft == rit) return a[lft];
    if (dp[lft][rit] != -1) return dp[lft][rit];
    if (move % 2) { //player 1's turn
        return dp[lft][rit] = max(a[lft] - fun(lft + 1, rit, move + 1), a[rit] - fun(lft, rit - 1, move + 1));
    } else { //player 2's turn
        if (a[lft] > a[rit] || a[lft] == a[rit]) return a[lft] - fun(lft + 1, rit, move + 1);
        else return a[rit] - fun(lft, rit - 1, move + 1);
    }
}

void solve() {

    int cnt = 1;
    while (true) {
        cin >> n; if (n == 0) break;
        for (int i = 0; i < n; i++) cin >> a[i]; ms(dp, -1);

        cout << "In game " << cnt++ << ", the greedy strategy might lose by as many as "<< fun(0, n-1, 1) << " points." << nl;

    }

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}