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
const int MN = 500005;
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

int N, Q; int psa[11][MN], lft[MN], rit[MN]; int arr[MN];

void solve() {

    cin >> N >> Q;
    for (int i=1; i<=N; i++) {
        cin >> arr[i]; lft[i] = max(lft[i-1], arr[i]); psa[arr[i]][i] = 1;
        for (int j=1; j<=10; j++) {
            psa[j][i] += psa[j][i-1];
        }
    }
    for (int i=N; i>=1; i--) rit[i] = max(rit[i+1], arr[i]);
    for (int i=1; i<=Q; i++) {
        int a, b; cin >> a >> b;
        int mx = max(lft[a-1], rit[b+1]);
        int cnt = psa[mx][N] - psa[mx][b] + psa[mx][a-1];
        cout << mx << " " << cnt << nl;
    }

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}