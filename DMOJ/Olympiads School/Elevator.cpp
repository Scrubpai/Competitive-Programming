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

struct Q {
    int t, s, d;
};
int n, t, m; Q a[105];

void solve() {

    cin >> n >> t >> m; // n = # OF FLOORS, T = TIME REQ FOR ELEVATOR TO MOVE BETWEEN FLOORS, M = # OF PASS
    for (int i = 1; i <= m; i++) {
        int T, s, d; cin >> T >> s >> d; a[i] = {T, s, d};
    }
    int sum = 0;
    for (int i = 1; i <= m; i++) {
        int time = 0, cur = 0; bool up = true, down = false;
        while (true) {
            if (time >= a[i].t && cur == a[i].s) {
                if (up && a[i].s > a[i].d) {
                    time += 2 * (n-a[i].s) * t;
                } else if (down && a[i].s < a[i].d) {
                    time += 2 * a[i].s * t;
                }
                break;
            }
            if (up) cur++;
            else if (down) cur--;
            if (cur == 0) { up = true; down = false;}
            else if (cur == n) { up = false; down = true; }
            time+=t;

        }
        sum += (time-a[i].t) + abs(a[i].d - a[i].s)*t;
    }
    cout << sum << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}