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
const int MN = (int)2e5 + 5;
const ll MOD = 998244353;

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

int a[2*MN]; int ans[MN];

void solve() {

    int q; cin >> q;
    while (q--) {
        int n; cin >> n; bool eq = true; int tmp = -1;
        rep1(i, 1, n) {
            cin >> a[i]; a[i+n] = a[i];
            if (tmp==-1) tmp=a[i];
            else {
                if (tmp!=a[i]) eq = false;
            }
        }
        if (eq) {
            cout << 1 << nl;
            rep(i, 0, n) cout << 1 << " ";
            cout << nl;
            continue;
        }

        if (n%2==0) {
            cout << 2 << nl;
            rep1(i, 1, n) {
                if (i%2==1) cout << 1 << " ";
                else cout << 2 << " ";
            }
            cout << nl;
            continue;
        }

        bool check = false; int pos;
        rep1(i, 1, n) {
            if (a[i]==a[i+1]) { check = true; pos=i; break; }
        }

        if (check) {
            cout << 2 << nl;
            ans[1] = 1;
            for (int i=2; i<=pos; i++) ans[i] = -ans[i-1]+3;
            ans[pos+1] = ans[pos];
            for (int i=pos+2; i<=n; i++) ans[i] = -ans[i-1]+3;

            rep1(i, 1, n) cout << ans[i] << " ";
            cout << nl;
        } else {
            cout << 3 << nl;
            rep(i, 1, n) {
                if (i%2==1) cout << 1 << " ";
                else cout << 2 << " ";
            }
            cout << 3 << nl;
        }

    }

}

int32_t main() {
   // ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}

