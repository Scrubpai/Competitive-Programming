#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<string> vs;
typedef complex<double> pnt;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define rep1(i, a, n) for (int i=a; i<=n; i++)
#define per(i,a,n) for (int i=a-1;i>=n;i--)
#define per1(i,a,n) for (int i=a;i>=n;i--)
#define endl '\n'
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
#define f first
#define s second
#define nl '\n'
typedef unsigned long long ull;
const int MN = (int)2e4 + 5;
const int MOD = (int)1e9 + 7;

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

struct event {
    int u, v, w, f;
};
bool cmp(event a, event b) { return a.w < b.w || (a.w==b.w&&a.f<b.f); }

int N, M, K, S, T, lst_weight; vector<event> vec; unordered_set<int> adj[1002]; int ans;
bool vis[1002];

void updateEdge(int i) {
    if (vec[i].f > 0) adj[vec[i].u].insert(vec[i].v);
    else adj[vec[i].u].erase(vec[i].v);
}

bool bfs(int st, int t) {
    ms(vis, false); queue<int> q; q.push(st); vis[st] = true;
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (int v : adj[cur]) {
            if (!vis[v]) {
                q.push(v); vis[v] = true;
            }
        }
    }

    return vis[t];
}

void solve() {

    cin >> N >> M >> K >> S >> T;
    for (int i=1; i<=M; i++) {
        int a, b, c, d; cin >> a >> b >> c >> d;
        vec.pb({a, b, c, 1}); vec.pb({a, b, d+1, -1});
    }
    sort(vec.begin(), vec.end(), cmp);
    for (int i=0; i<vec.size(); i++) {
        int cur_weight = vec[i].w; bool flag = vis[T];
        updateEdge(i);
        for (; i+1 < vec.size() && vec[i+1].w==cur_weight; i++) updateEdge(i+1);
        if (bfs(S, T)) {
            ans += (flag? cur_weight-lst_weight: 1);
        } else if (flag) ans += cur_weight - lst_weight - 1;

        lst_weight = cur_weight;
    }

    cout << ans << nl;

}

int32_t main() {
    solve();
    return 0;
}