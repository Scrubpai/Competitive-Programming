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
#define f first
#define s second
#define nl '\n'
typedef unsigned long long ull;
const int MN = 1e5 + 5;
const int MOD = 998244353;

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

void solve() {
    double x1, y1, x2, y2, x3, y3, x4, y4; cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    double A1 = (y1-y2), B1 = (x2-x1), C1 = - (y1*(x2-x1)-(y2-y1)*x1);
    double A2 = (y3-y4), B2 = (x4-x3), C2 = - (y3*(x4-x3)-(y4-y3)*x3);

    if (A1*B2==A2*B1) {
        if (C1*B2==C2*B1) cout << "coincident" << nl;
        else cout << "parallel" << nl;
    } else {
        double x = (B1*C2 - B2*C1) / (B2*A1 - B1*A2);
        double y = (A1*C2 - A2*C1) / (A2*B1 - A1*B2);
        printf("%.6f", x); cout << " "; printf("%.6f", y); cout << nl;
    }
}

int32_t main() {
    solve();
    return 0;
}