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

int va, vb, m, dis[1005][1005], vis[1005][1005]; string p[1005][1005]; pii pre[1005][1005]; queue<pii> q; vector<string> ord;

void solve(int tc) {

    cin >> va >> vb >> m; ms(dis, INF);
    if (va < m && vb < m) { cout << "Not possible" << nl; return; }
    vis[0][0] = 1; dis[0][0] = 0; q.push({0, 0}); pre[0][0] = {-1, -1};
    while (!q.empty()) {
        pii cur = q.front(); q.pop();
        int a = cur.first, b = cur.second;
        if (a < va && !vis[va][b]) {
            vis[va][b] = 1; dis[va][b] = dis[a][b] + 1; pre[va][b] = {a, b}; q.push({va, b}); p[va][b] = "fill A";
        }
        if (b < vb && !vis[a][vb]) {
            vis[a][vb] = 1; dis[a][vb] = dis[a][b] + 1; pre[a][vb] = {a, b}; q.push({a, vb}); p[a][vb] = "fill B";
        }
        if (a < va && b > 0) {
            int na = min(va, a + b), nb = b - (na - a);
            if (!vis[na][nb]) {
                vis[na][nb] = 1; dis[na][nb] = dis[a][b] + 1; pre[na][nb] = {a, b}; q.push({na, nb}); p[na][nb] = "pour B A";
            }
        }
        if (a > 0 && b < vb) {
            int nb = min(vb, a + b), na = a - (nb - b);
            if (!vis[na][nb]) {
                vis[na][nb] = 1; dis[na][nb] = dis[a][b] + 1; pre[na][nb] = {a, b}; q.push({na, nb}); p[na][nb] = "pour A B";
            }
        }
        if (a > 0 && !vis[0][b]) {
            vis[0][b] = 1; dis[0][b] = dis[a][b] + 1; pre[0][b] = {a, b}; q.push({0, b}); p[0][b] = "chug A";
        }
        if (b > 0 && !vis[a][0]) {
            vis[a][0] = 1; dis[a][0] = dis[a][b] + 1; pre[a][0] = {a, b}; q.push({a, 0}); p[a][0] = "chug B";
        }
    }
    int mndis = INF; int a = -1, b = -1;
    for (int i = 0; i <= max(va, vb); i++) {
        if (dis[i][m] < mndis) {
            mndis = dis[i][m]; a = i; b = m;
        }
        if(dis[m][i] < mndis) {
            mndis = dis[m][i]; a = m; b = i;
        }
    }
    
    if (mndis == INF) cout << "Not possible" << nl;
    else {
        while (a != 0 || b != 0) {
            ord.push_back(p[a][b]);
            int tmpa = a, tmpb = b;
            a = pre[tmpa][tmpb].first; b = pre[tmpa][tmpb].second;
        }
        for (int i = ord.size() - 1; i >= 0; i--) cout << ord[i] << nl;
    }

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tc = 1; //cin >> tc;
    for (int t = 0; t < tc; t++) solve(t);

    return 0;
}