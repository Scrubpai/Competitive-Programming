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
typedef double ld;
typedef long double lld;
#define INF 0x3f3f3f3f // for int
#define LL_INF 0x3f3f3f3f3f3f3f3f // for ll
#define gl(x) getline(cin, (x))
#define sz(x) (int)(x.size())
#define af(x) x.begin(), x.end()
#define ms(x, y) memset(x, y, sizeof(x))
#define mpp make_pair
#define pb push_back
#define AUT auto
#define nl '\n'
typedef unsigned long long ull;
const int MOD = 1e9 + 7;
const lld pi = 3.14159265358979323846;

ll gcd(ll a, ll b){return b == 0 ? a : gcd(b, a % b);}
ll lcm(ll a, ll b){return a*b/gcd(a,b);}
ll pwmd(ll b, ll exp) {
    ll ret = 1;
    while (exp > 0) {
        if (exp % 2 == 1) ret = (ret * b) % MOD;
        exp /= 2;
        b = (b * b) % MOD;
    }
    return ret;
}

int h, w, n, a[3005][3005], mx[3005][3005], mn[3005][3005], mn2[3005][3005], mx2[3005][3005]; deque<int> dqmin, dqmax;

void pushmin(deque<int> &dq, int x) {
    while (!dq.empty() && dq.back() > x) dq.pop_back();
    dq.push_back(x);
}
void pushmax(deque<int> &dq, int x) {
    while (!dq.empty() && dq.back() < x) dq.pop_back();
    dq.push_back(x);
}

void solve(int tc) {

    cin >> h >> w >> n; ms(mn, INF);
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= h; i++) {
        while (!dqmin.empty()) dqmin.pop_back();
        while (!dqmax.empty()) dqmax.pop_back();
        for (int j = 1; j <= w; j++) {
            if (j > n && a[i][j-n] == dqmin.front()) { dqmin.pop_front(); }
            if (j > n && a[i][j-n] == dqmax.front()) { dqmax.pop_front(); }
            pushmin(dqmin, a[i][j]); pushmax(dqmax, a[i][j]);
            if (j >= n) {
                mx[i][j] = max(mx[i][j], dqmax.front());
                mn[i][j] = min(mn[i][j], dqmin.front());
            }
        }
    }
    while (!dqmin.empty()) dqmin.pop_back(); while(!dqmax.empty()) dqmax.pop_back();
    for (int j = n; j <= w; j++) {
        while (!dqmin.empty()) dqmin.pop_back();
        while (!dqmax.empty()) dqmax.pop_back();
        for (int i = 1; i <= h; i++) {
            if (i > n && mn[i-n][j] == dqmin.front()) dqmin.pop_front();
            if (i > n && mx[i-n][j] == dqmax.front()) dqmax.pop_front();
            pushmin(dqmin, mn[i][j]); pushmax(dqmax, mx[i][j]);
            if (i >= n) {
                mn2[i][j] = min(mn[i][j], dqmin.front());
                mx2[i][j] = max(mx[i][j], dqmax.front());
            }
        }
    }
    int ans = INF;
    for (int i = n; i <= h; i++) {
        for (int j = n; j <= w; j++) {
            ans = min(ans, mx2[i][j] - mn2[i][j]);

        }
    }
    cout << ans << nl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tc = 1;// cin >> tc;
    for (int t = 0; t < tc; t++) solve(t);

    return 0;
}