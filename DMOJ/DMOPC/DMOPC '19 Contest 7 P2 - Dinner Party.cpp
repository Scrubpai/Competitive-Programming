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
const int MN = 1000005;
const int MOD = 1000000007;

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
    int lft, rit, num;
};

int n; int a[MN], tmpa[MN]; vector<Q> moves;

void copy() {
    for (int i = 0; i <n; i++) tmpa[i] = a[i];
}

void solve() {

    cin >> n; int sum = 0;
    for (int i = 0; i < n; i ++) { cin >> a[i]; sum += a[i]; } if (sum % 2 == 1) { cout << "NO" << nl; return; }

    for (int i = 0; i < n; i ++) {
        int lft = a[(i-1+n) % n]; int rit = a[(i+1) % n];

        if (lft + rit < a[i]) { cout << "NO" << nl; return; }
    }

    bool test = false; int cnt = 0;
    for (int num = 0; num <= a[n-1]; num++) {
        if (a[0] - num < 0) continue;
        int val = a[0] - num; if (val > a[1]) continue;
        moves.clear(); copy(); cnt = 0; tmpa[0] = 0; tmpa[n-1] -= num; tmpa[1] -= val;
        moves.push_back({0, n-1, num});  moves.push_back({0, 1, val}); cnt += val + num;

        bool flag = true;
        for (int i = 1; i < n; i ++) {
            if (tmpa[i] < 0) { flag = false; break; }
            if (tmpa[i] == 0) continue;

            moves.push_back({i, (i+1)%n, tmpa[i]}); cnt += tmpa[i];
            tmpa[(i+1) % n] -= tmpa[i]; tmpa[i] = 0;
        }
        if (tmpa[0] != 0) flag = false;
        if (flag) { test = true; break; }
    }

    if (!test) cout << "NO" << nl;
    else {
        cout << "YES" << nl << cnt << nl;
        for (Q q : moves) {
            for (int t = 1; t <= q.num; t++) cout << q.lft << " " << q.rit << nl;
        }
    }

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}