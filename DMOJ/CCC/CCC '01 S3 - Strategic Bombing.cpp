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

vector<int> adj[30]; bool vis[30]; char a, b; vector<pii> edges;

bool bfs(int u, int v) {
    vis[0] = 1; queue<int> q; q.push(0);
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (int n : adj[cur]) {
            if ((cur == u && n == v) || (cur == v && n == u)) continue;
            if (vis[n]) continue;
            vis[n] = 1; q.push(n);
        }
    }
    return vis[1];
}

void solve(int tc) {

    cin >> a >> b; int cnt = 0;
    while (a != '*' && b != '*') {
        adj[a-'A'].push_back(b-'A');
        adj[b-'A'].push_back(a-'A');
        edges.push_back({a-'A', b-'A'});
        cin >> a >> b;
    }
    for (int i = 0; i < edges.size(); i++) {
        int x = edges[i].first, y = edges[i].second; ms(vis, 0);
        if (!bfs(x, y)) {
            a = x + 'A'; b = y + 'A';
            cout << a << b << nl;
            cnt++;
        }
    }
    cout << "There are " << cnt << " disconnecting roads." << nl;


}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tc = 1;// cin >> tc;
    for (int t = 0; t < tc; t++) solve(t);

    return 0;
}