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

const int MM = 5003;
int N, M, K, Q; ll dif[MM][MM], psa[MM][MM];

void solve() {

    scanf("%d %d %d", &N, &M, &K);
    for (int i = 1, r1, c1, r2, c2; i <= K; i++) {
        scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
        r2++; c2++;
        dif[r1][c1]++; dif[r1][c2]--; dif[r2][c1]--; dif[r2][c2]++;
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            dif[i][j] += dif[i-1][j] + dif[i][j-1] - dif[i-1][j-1];
            psa[i][j] += psa[i-1][j] + psa[i][j-1] - psa[i-1][j-1] + dif[i][j];
        }
    }
    scanf("%d", &Q);
    for (int i = 1, r1, c1, r2, c2; i <= Q; i++) {
        scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
        r1--; c1--;
        printf("%lld\n", psa[r2][c2] - psa[r1][c2] - psa[r2][c1] + psa[r1][c1]);
    }

}

int32_t main() {
  //  ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}