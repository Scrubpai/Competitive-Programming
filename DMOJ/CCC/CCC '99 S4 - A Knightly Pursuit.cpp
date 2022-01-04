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

int r, c, pr, pc, kr, kc, dir[8][2] = {{-2, -1}, {-2, 1}, {-1, 2}, {-1, -2}, {1, 2}, {1, -2}, {2, 1}, {2, -1}}, dis[105][105];

void solve(int tc) {

    cin >> r >> c >> pr >> pc >> kr >> kc; queue<pii> q; ms(dis, -1); dis[kr][kc] = 0; q.push({kr, kc});
    while (!q.empty()) {
        pii cur = q.front(); q.pop();
        for (int k = 0; k < 8; k++) {
            int nr = cur.first + dir[k][0], nc = cur.second + dir[k][1];
            if (nr >= 1 && nr <= r && nc >= 1 && nc <= c && dis[nr][nc] == -1) {
                dis[nr][nc] = dis[cur.first][cur.second] + 1; q.push({nr, nc});
            }
        }
    }
    bool win = 0; int w = 0, s = -1; // w = win, s = stalemate
    for (int i = pr; i < r && !win; i++) {
        int move = i - pr;
        if (dis[i][pc] >= 0 && dis[i][pc] <= move && (move - dis[i][pc]) % 2 == 0) {
            win = 1; w = move;
        }
        if (s == -1 && dis[i+1][pc] >= 0 && dis[i+1][pc] <= move && (move - dis[i+1][pc]) % 2 == 0) {
            s = move;
        }
    }
    if (win) cout << "Win in " << w << " knight move(s)." << nl;
    else if (s!=-1) cout << "Stalemate in " << s << " knight move(s)." << nl;
    else cout << "Loss in " << (r-pr-1) << " knight move(s)." << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tc = 1; cin >> tc;
    for (int t = 0; t < tc; t++) solve(t);

    return 0;
}