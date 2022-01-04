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

char ch; int x, y; bool adj[50][50], vis[50]; int dis[50];

void bfs(int start) {
    queue<int> q; q.push(start); dis[start] = 0;
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (int i = 1; i < 50; i++) {
            if (adj[cur][i] && dis[i] == -1) {
                dis[i] = dis[cur] + 1; q.push(i);
            }
        }
    }
}

void solve() {

    adj[1][6] = adj[2][6] = adj[3][6] = adj[3][4] = adj[3][15] = adj[3][5] = adj[4][3] = adj[4][5] = adj[4][6] = adj[5][4] = adj[5][6] = true;
    adj[5][3] = adj[6][1] = adj[6][2] = adj[6][7] = adj[6][5] = adj[6][4] = adj[6][3] = adj[7][6] = adj[7][8] = adj[8][7] = true;
    adj[8][9] = adj[9][8] = adj[9][10] = adj[9][12] = adj[10][9] = adj[10][11] = adj[11][10] = adj[11][12] = true;
    adj[12][9] = adj[12][11] = adj[12][13] = adj[13][12] = adj[13][15] = adj[13][14] = adj[14][13] = adj[15][13] = true;
    adj[15][3] = adj[16][17] = adj[16][18] = adj[17][16] = adj[17][18] = adj[18][16] = adj[18][17] = true;
    while (1) {
        cin >> ch;
        if (ch == 'q') break;
        else if (ch == 'i') {
            cin >> x >> y; adj[x][y] = adj[y][x] = true;
        } else if (ch == 'd') {
            cin >> x >> y; adj[x][y] = adj[y][x] = false;
        } else if (ch == 'n') {
            cin >> x; int cnt = 0;
            for (int i = 1; i < 50; i++) {
                if (adj[x][i]) { cnt++; }
            }
            cout << cnt << nl;
        } else if (ch == 'f') {
            cin >> x; int cnt = 0;
            for (int i = 1; i < 50; i++) { vis[i] = false; }
            for (int i = 1; i < 50; i++) {
                if (adj[x][i]) {
                    for (int j = 1; j < 50; j++) {
                        if (j != x && !adj[x][j] && !vis[j] && adj[i][j]) { cnt++; vis[j] = true; }
                    }
                }
            }
            cout << cnt << nl;
        } else if (ch == 's') {
            cin >> x >> y; for (int i = 1; i < 50; i++) dis[i] = -1; bfs(x);
            if (dis[y] == -1) cout << "Not connected" << nl;
            else cout << dis[y] << nl;
        }
    }

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}