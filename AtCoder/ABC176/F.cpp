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

int n, dp[6005][6005], a[6005], label[6005], add, nxt[2005][2005], ans, tmp; vector<int> cards, groups[2005], pos[2005];
/*
 * dp[i][j]: (i < j) we have cards at idx i and j in our hand and we have just "exchanged" with the group label[j]
 * - you always assume you have exchanged something in this state
 * nxt[i][j]: the position of first element equal to i with label j
 */

int check(int i, int j, int k) {
    if (cards[i] == cards[j] && cards[j] == cards[k]) return 1;
    else return 0;
}

void update(int x, int y, int u, int v, int w) {
    //you have cards x, y; exchange with cards u, v, w;
    dp[x][u] = max(dp[x][u], dp[x][y] + check(y, v, w));
    dp[x][v] = max(dp[x][v], dp[x][y] + check(y, u, w));
    dp[x][w] = max(dp[x][w], dp[x][y] + check(y, u, v));
    dp[y][u] = max(dp[y][u], dp[x][y] + check(x, v, w));
    dp[y][v] = max(dp[y][v], dp[x][y] + check(x, u, w));
    dp[y][w] = max(dp[y][w], dp[x][y] + check(x, u, v));
    dp[u][v] = max(dp[u][v], dp[x][y] + check(x, y, w));
    dp[u][w] = max(dp[u][w], dp[x][y] + check(x, y, v));
    dp[v][w] = max(dp[v][w], dp[x][y] + check(x, y, u));
}

void go2(int i, int j, int idx) {
    int nxt_label = label[idx];
    if (nxt_label != tmp) {
        update(i, j, groups[nxt_label][0], groups[nxt_label][1], groups[nxt_label][2]);
    } else {
        ans = max(ans, dp[i][j] + check(i, j, cards.size() - 1));
    }
}

void go(int i, int j) {
    if (label[j] + 1 == tmp) { ans = max(ans, dp[i][j] + check(i, j, cards.size() - 1)); return; }
    //second transition
    int idx1 = nxt[cards[i]][label[j]+1], idx2 = nxt[cards[j]][label[j]+1];
    if (idx1 != -1) go2(i, j, idx1);
    if (idx2 != -1) go2(i, j, idx2);
    //first transition
    update(i, j, groups[label[j]+1][0], groups[label[j]+1][1], groups[label[j]+1][2]);
}

void solve(int tc) {

    cin >> n; cards.push_back(-1);
    for (int i = 1; i <= 3 * n; i++) {
        cin >> a[i]; 
    }
    cards.push_back(a[1]); cards.push_back(a[2]); //cards 1 and 2 already have label 0
    int _n = 2;
    for (int i = 3; i <= 3 * n - 3; i += 3) {
        if (a[i] == a[i+1] && a[i+1] == a[i+2]) add++;
        else {
            cards.push_back(a[i]); cards.push_back(a[i+1]); cards.push_back(a[i+2]);
            tmp++; label[_n+1] = label[_n+2] = label[_n+3] = tmp;
            groups[tmp].push_back(_n+1); groups[tmp].push_back(_n+2); groups[tmp].push_back(_n+3); _n += 3;
        }
    }
    cards.push_back(a[3*n]); tmp++; _n++; label[_n] = tmp; 
    for (int i = 1; i <= _n; i++) pos[cards[i]].push_back(i);
    ms(dp, -1); ms(nxt, -1); dp[1][2] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j : pos[i]) { //pos is sorted
            int cur_label = label[j];
            while (cur_label > 0 && nxt[i][cur_label] == -1) {
                nxt[i][cur_label] = j;
                cur_label--;
            }
        }
    }
    //compute dp
    for (int i = 2; i < cards.size(); i++) {
        for (int j = 1; j < i; j++) {
            if (dp[j][i] != -1) {
                go(j, i);
            }
        }
    }
    cout << ans + add << nl;

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