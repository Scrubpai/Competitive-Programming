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
const int MN = (int)(pow(2, 20));
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

int n, h[17], dp[1 << 16]; int T = 5;

bool isIncOrDec(int mask) {
    vector<int> list;
    for (int k=0; k<n; k++) {
        if ((mask & 1 << k) != 0) list.push_back(h[k]);
    }
    bool inc = true, dec = true;
    for (int k=1; k<list.size(); k++) {
        if (list[k] > list[k-1]) dec = false;
        if (list[k] < list[k-1]) inc = false;
    }
    return (inc || dec);
}

//1 = lose, 0 = win
int fun(int mask) {
    if (dp[mask]!=-1) return dp[mask];
    if (isIncOrDec(mask)) return dp[mask] = 1; //lose
    int result = 0;
    for (int k=0; k<n; k++) {
        if ((mask & 1 << k) != 0) result |= fun(mask ^ (1 << k));
    }
    return dp[mask]= result==1? 0:1;
                    //if result is lose, current is win
                    //if result is win (every possible outcome is win), current position is lose
}

void solve() {

    while (T--) {
        string ans = "";
        for (int t=1; t<=3; t++) {
            cin >> n;
            for (int i=0; i<(1<<n); i++) dp[i] = -1;
            for (int i=0; i<n; i++) cin >> h[i];
            if (fun((1 << n) - 1)==1) ans += "B";
            else ans += "A";
        }
        cout << ans << nl;
    }

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}