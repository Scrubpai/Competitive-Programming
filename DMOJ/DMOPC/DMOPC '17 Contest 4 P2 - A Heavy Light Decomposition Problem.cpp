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

int n, q, op, v[1002], st, ed; vector<int> adj[1002], tmp;

void dfs(int cur, int pa, vector<int> &t) {
    t.push_back(v[cur]);
    if (cur == ed) {
        if (op == 1) {
            double ans = 0;
            for (int x : t) ans += x;
            ans /= t.size();
            cout << (int)(ans + 0.5) << nl;
        } else if (op == 2) {
            sort(t.begin(), t.end());
            int mid = t.size() / 2;
            if (t.size() % 2 == 1) cout << t[mid] << nl;
            else cout << (int)((double)(t[mid] + t[mid-1])/2.0 + 0.5) << nl;
        } else {
            sort(t.begin(), t.end());
            int pre = -1, cnt = 0, most = 0, val = 0;
            for (int i = 0; i < t.size(); i++) {
                if (t[i] != pre) cnt = 1;
                else { cnt++; }
                if (cnt > most) { most = cnt; val = t[i]; }
                else if (cnt == most) { val = min(val, t[i]); }
                pre = t[i];
            }
            cout << val << nl;
        }
        return;
    }
    for (int u : adj[cur]) {
        if (u != pa) {
            dfs(u, cur, t);
        }
    }
    t.pop_back();
}

void solve() {

    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> v[i];
    for (int i = 1; i < n; i++) {
        int x, y; cin >> x >> y; adj[x].push_back(y); adj[y].push_back(x);
    }
    for (int i = 1; i <= q; i++) {
        cin >> op >> st >> ed; tmp.clear();
        dfs(st, 0, tmp);
    }

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}