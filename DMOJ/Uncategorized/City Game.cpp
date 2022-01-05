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

int k, m, n, dp[1001][1001]; bool city[1001][1001]; deque<int> dq; int ans;

void push(int x, int row) {
    while (!dq.empty() && dp[row][dq.back()] > dp[row][x]) {
        ans = max(ans, dp[row][dq.back()] * (x - dq.back()));
        dq.pop_back();
    }
    dq.push_back(x);
}

void solve() {

    cin >> k;
    while (k--) {
        scanf(" %d %d", &m, &n); ans = 0;
        for (int r = 1; r <= m; r++) {
            for (int c = 1; c <= n; c++) {
                char ch; cin >> ch;
                if (ch == 'F') city[r][c] = 1;
                else city[r][c] = 0;
            }
        }
        for (int r = 1; r <= m; r++) {
            for (int c = 1; c <= n; c++) {
                if (city[r][c] == 0) dp[r][c] = 0;
                else dp[r][c] = dp[r-1][c] + 1;
                push(c, r);
            }
            //n columns
            while (!dq.empty()) {
                ans = max(ans, dp[r][dq.back()] * (n - dq.back() + 1));
                dq.pop_back();
            }
        }
        cout << ans*3 << nl;
    }

}

int32_t main() {
  //  ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}