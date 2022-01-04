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
#define nl '\n'
typedef unsigned long long ull;
const int MOD = 1000000000;

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

int T = 5, n; bool notPrime[105];

void sieve() {
    notPrime[1] = true;
    for (int i = 2; i <= 100; i++) {
        if (notPrime[i]) continue;
        for (int j = i * i; j <= 100; j += i) {
            notPrime[j] = true;
        }
    }
}

void solve() {

    sieve();
    while (T--) {
        cin >> n; int prev = -1, after = -1;
        for (int i = n - 1; i > 1; i--) {
            if (!notPrime[i] && prev == -1) prev = i;
            else if (!notPrime[i] && prev != -1) { prev = i; break; }
        }
        for (int i = n + 1; i; i++) {
            if (!notPrime[i] && after == -1) after = i;
            else if (!notPrime[i] && after != -1) { after = i; break; }
        }
        int ans;
        if (n - prev < after - n) ans = prev;
        else ans = after;
        cout << ans << nl;
    }

}

int32_t main() {
  //  ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}