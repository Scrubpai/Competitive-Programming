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

vector<int> a;

void solve() {

    int G; cin >> G;
    while (G--) {
        int N; cin >> N; a.clear();
        for (int i=0; i<N; i++) {
            int dmg; cin >> dmg; a.pb(dmg);
        }
        sort(a.begin(), a.end());
        int Hi, Hm; cin >> Hi >> Hm; bool flag = false;
        do {
            int tmpHi = Hi, tmpHm = Hm; vector<int> tmpa = a;
            while (!tmpa.empty() && tmpHm > 0) { tmpHm -= tmpa[0]; tmpa.erase(tmpa.begin()); }
            while (!tmpa.empty() && tmpHi > 0) { tmpHi -= tmpa[0]; tmpa.erase(tmpa.begin()); }
            if (tmpHi <= 0) { flag = true; break; }
        } while (next_permutation(a.begin(), a.end()));
        if (flag) cout << "LETHAL" << nl;
        else cout << "NOT LETHAL" << nl;
    }

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}