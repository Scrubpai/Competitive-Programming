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
//#define f first
//#define s second
#define nl '\n'
typedef unsigned long long ull;
const int MOD = 10;

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

int amt, r, c; char grid[30][30]; vector<int> areas;
int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}}; int area;

void bfs(int i, int j) {
    if (i < 1 || j < 1 || i > r || j > c) return;
    area++;
    grid[i][j] = 'I';
    if (grid[i+1][j] == '.') bfs(i + 1, j);
    if (grid[i][j+1] == '.') bfs(i, j + 1);
    if (grid[i-1][j] == '.') bfs(i - 1, j);
    if (grid[i][j-1] == '.') bfs(i, j - 1);
}

void solve() {

    cin >> amt >> r >> c;
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            cin >> grid[i][j];
        }
    }
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            if (grid[i][j] == 'I') continue;
            area = 0;
            bfs(i, j);
            areas.push_back(area);
        }
    }
    sort(areas.begin(), areas.end(), greater<int>());
    int cnt = 0;
    for (int i = 0; i < areas.size(); i++) {
        if (amt - areas[i] >= 0) {
            amt -= areas[i];
            cnt++;
        } else {
            break;
        }
    }
    if (cnt == 1) cout << cnt << " room, " << amt << " square metre(s) left over" << nl;
    else cout << cnt << " rooms, " << amt << " square metre(s) left over" << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}