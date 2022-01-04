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

string tmp = "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";
int r, c; char grid[25][25]; string ans = "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";

string checkvert(int i, int j) {
    string ret = "";
    for (int k = i; k <= r; k++) {
        if (grid[k][j] == '#') break;
        else ret += grid[k][j];
    }
    if (ret.size() < 2) return tmp;
    else return ret;
}

string checkhoriz(int i, int j) {
    string ret = "";
    for (int k = j; k <= c; k++) {
        if (grid[i][k] == '#') break;
        else ret += grid[i][k];
    }
    if (ret.size() < 2) return tmp;
    else return ret;
}

bool comp(string s1, string s2) {
    return s1 + s2 > s2 + s1;
}

void solve() {

    cin >> r >> c;
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            cin >> grid[i][j];
        }
    }
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            if (grid[i][j] == '#') continue;
            if (i == 1 || grid[i-1][j] == '#') {
                string str = checkvert(i, j);
                ans = min(ans, str);
            }
            if (j == 1 || grid[i][j-1] == '#') {
                string str = checkhoriz(i, j);
                ans = min(ans, str);
            }
            if (ans == "bb") cout << i << " " << j << nl;
        }
    }

    cout << ans << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}