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

const int MM = 1e5 + 4; string str;
int N, M, K, dis[26][26], psa[MM][26], best[MM][26], dp[MM];

void solve() {

    cin >> N >> M >> K >> str;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            cin >> dis[i][j];
        }
    }
    //floyd warshall
    for (int k = 0; k < M; k++) {
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < M; j++) {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
    //build psa (1d): psa[i][p]: change string 1->i all to a letter p
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < M; j++) {
            psa[i][j] = psa[i-1][j] + dis[str[i-1] - 'a'][j];
        }
    }
    //DP
    ms(dp, INF); dp[0] = 0;
    for (int i = K; i <= N; i++) {
        for (int p = 0; p < M; p++) {
            dp[i] = min(dp[i], best[i-K][p] + psa[i][p]);
        }
        for (int p = 0; p < M; p++) {
            best[i][p] = min(best[i-1][p], dp[i] - psa[i][p]);
        }
    }
    cout << dp[N] << nl;

}

int32_t main() {
  //  ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}