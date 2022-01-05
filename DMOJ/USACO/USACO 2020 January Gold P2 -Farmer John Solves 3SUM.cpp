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

const int MM = 5005, MV = 1e6 + 3;
int N, Q, a[MM], cnt[2*MV]; ll psa[MM][MM];

void solve() {

    cin >> N >> Q;
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
    }
    for (int i = N-1; i >= 1; i--) {
        for (int k = i + 1; k <= N; k++) {
            int val = -(a[i] + a[k]) + MV;
            if (val >= 0 && val < 2 * MV) psa[i][k] = cnt[val];
            cnt[a[k] + MV] ++;
        }
        for (int k = i + 1; k <= N; k++) {
            cnt[a[k] + MV]--;
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            psa[i][j] += psa[i-1][j] + psa[i][j-1] - psa[i-1][j-1];
        }
    }
    while (Q--) {
        int x, y; cin >> x >> y;
        printf("%lld\n", psa[y][y] - psa[x-1][y] - psa[y][x-1] + psa[x-1][x-1]);
    }

}

int32_t main() {
  //  ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}