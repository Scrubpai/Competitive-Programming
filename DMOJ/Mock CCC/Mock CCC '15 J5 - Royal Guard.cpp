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

const int MM = 1e5 + 5;
int n, m; pii pt[MM]; vector<pii> bx, by; ll ans;

void solve(int tc) {

    cin >> n;
    for (int i = 1, x, y; i <= n; i++) {
        cin >> x >> y;
        bx.push_back({x, y}); by.push_back({y, x});
    }
    sort(bx.begin(), bx.end()); sort(by.begin(), by.end());
    cin >> m;
    for (int i = 1, x, y; i <= m; i++) {
        cin >> x >> y;
        pt[i] = {x, y};
    }
    for (int i = 2; i <= m; i++) {
        int x1 = pt[i-1].first, y1 = pt[i-1].second, x2 = pt[i].first, y2 = pt[i].second;
        if (y1 == y2) {
            int a = lower_bound(by.begin(), by.end(), make_pair(y1, min(x1, x2))) - by.begin();
            int b = upper_bound(by.begin(), by.end(), make_pair(y1, max(x1, x2))) - by.begin();
            ans += (b - a);
        } else {
            int a = lower_bound(bx.begin(), bx.end(), make_pair(x1, min(y1, y2))) - bx.begin();
            int b = upper_bound(bx.begin(), bx.end(), make_pair(x1, max(y1, y2))) - bx.begin();
            ans += (b - a);
        }
    }
    cout << ans << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tc = 1; //cin >> tc;
    for (int t = 0; t < tc; t++) solve(t);

    return 0;
}