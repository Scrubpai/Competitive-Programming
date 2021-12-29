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
//coordinate compression:sort(val.begin(), val.end());
//		val.resize(unique(val.begin(), val.end()) - val.begin());
#define nl '\n'
typedef unsigned long long ull;
const lld pi = 3.14159265358979323846;
const ll MOD = 1e9 + 7;

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

const int MM = 1e6 + 5;

struct C {
    int w, h, id;
};
bool cmp(C a, C b) {
    return a.w < b.w;
}

int n, m; char ch, grid[105][105]; set<char> st; bool vis[105][105];

void fun(int r, int c) {
    vis[r][c] = 1;
    if (r - 1 >= 1) {
        if (grid[r-1][c] == ch && !vis[r-1][c]) fun(r-1, c);
        else if (grid[r-1][c] != ch && grid[r-1][c] != '.') st.insert(grid[r-1][c]);
    }
    if (c - 1 >= 1) {
        if (grid[r][c-1] == ch && !vis[r][c-1]) fun(r, c-1);
        else if (grid[r][c-1] != ch && grid[r][c-1] != '.') st.insert(grid[r][c-1]);
    }
    if (r + 1 <= n) {
        if (grid[r+1][c] == ch && !vis[r+1][c]) fun(r+1, c);
        else if (grid[r+1][c] != ch && grid[r+1][c] != '.') st.insert(grid[r+1][c]);
    }
    if (c + 1 <= m) {
        if (grid[r][c+1] == ch && !vis[r][c+1]) fun(r, c+1);
        else if (grid[r][c+1] != ch && grid[r][c+1] != '.') st.insert(grid[r][c+1]);
    }
}

void solve(int tc) {

    cin >> n >> m >> ch;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> grid[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (grid[i][j] == ch) {
                fun(i, j);
                cout << st.size() << nl; return;
            }
        }
    }

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tc = 1; //cin >> tc;
    for (int t = 0; t < tc; t++) solve(t);

    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
*/