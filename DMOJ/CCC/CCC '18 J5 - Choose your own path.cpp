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
    while (exp>0) {
        if (exp%2==1) ret = (ret*b)%MOD;
        exp/=2;
        b = (b*b)%MOD;
    }
    return ret;
}

int N, cnt, dis[10005]; bool vis[10005]; queue<int> q; vector<int> adj[10005];

void solve() {

    cin >> N;
    for (int i = 1; i <= N; i++) {
        int M; cin >> M;
        for (int j = 1; j <= M; j++) {
            int p; cin >> p;
            adj[i].push_back(p);
        }
    }
    int min_dis = INF; ms(dis, INF);
    q.push(1); cnt = 1; vis[1] = true; dis[1] = 1;
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (int v : adj[cur]) {
            if (!vis[v]) { vis[v] = true; q.push(v); cnt++; dis[v] = dis[cur] + 1; }
        }
    }
    if (cnt == N) cout <<"Y" << nl;
    else cout << "N" << nl;
    for (int i = 1; i <= N; i++) {
        if (adj[i].empty()) min_dis = min(min_dis, dis[i]);
    }
    cout << min_dis << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}