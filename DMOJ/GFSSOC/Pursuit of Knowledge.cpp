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

int N, M, T, Q, dis[1001][1001]; bool vis[1001]; vector<int> adj[1005];

void bfs(int st) {
    dis[st][st] = 0; queue<int> q; q.push(st); vis[st] = 1;
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (int v : adj[cur]) {
            if (!vis[v]) {
                vis[v] = 1; q.push(v); dis[st][v] = dis[st][cur] + 1;
            }
        }
    }
}

void solve() {

    cin >> N >> M >> T;
    for (int i = 1; i <= M; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
    }
    ms(dis, -1);
    for (int i = 1; i <= N; i++) {
        ms(vis, 0);
        bfs(i);
    }
    cin >> Q;
    for (int i = 1; i <= Q; i++) {
        int a, b; cin >> a >> b;
        if (dis[a][b] == -1) cout << "Not enough hallways!" << nl;
        else cout << dis[a][b] * T << nl;
    }

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}