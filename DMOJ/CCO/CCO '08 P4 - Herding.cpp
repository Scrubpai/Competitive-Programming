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

int n, m, ans, num[2005][2005], vis[2005][2005]; char grid[1005][1005]; unordered_map<char, pii> mp;

int dfs(int r, int c) {
    vis[r][c] = 1;
    int nr = r + mp[grid[r][c]].first, nc = c + mp[grid[r][c]].second;
    if (nr < 1 || nr > n || nc < 1 || nc > m) {
        vis[r][c] = 2; return num[r][c] = ++ans;
    }
    if (!vis[nr][nc]) num[r][c] = dfs(nr, nc);
    else if (vis[nr][nc] == 1) num[r][c] = ++ans;
    else if (vis[nr][nc] == 2) num[r][c] = num[nr][nc];
    vis[r][c] = 2;
    return num[r][c];
}

void solve(int tc) {

    cin >> n >> m;
    mp['S'] = {1, 0}; mp['N'] = {-1, 0}; mp['E'] = {0, 1}; mp['W'] = {0, -1};
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> grid[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (!vis[i][j]) {
                dfs(i, j);
            }
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