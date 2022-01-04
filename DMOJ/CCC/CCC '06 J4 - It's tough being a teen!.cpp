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

int in[100], ans[100]; vector<int> adj[100]; priority_queue<int ,vector<int>, greater<int>> pq; int u, v, num;

void solve() {

    in[1]++; in[7]++; in[4] += 2; in[5]++;
    adj[1].push_back(7); adj[1].push_back(4); adj[2].push_back(1); adj[3].push_back(4); adj[3].push_back(5);
    cin >> u >> v;
    while (u != 0 && v != 0) { in[v]++; adj[u].push_back(v);  cin >> u >> v; }
    for (int i = 1; i <= 7; i++) {
        if (in[i] == 0) pq.push(i);
    }
    while (!pq.empty()) {
        int cur = pq.top(); pq.pop(); ans[num++] = cur;
        for (int nxt : adj[cur]) {
            in[nxt]--;
            if (!in[nxt]) pq.push(nxt);
        }
    }
    if (num != 7) cout << "Cannot complete these tasks. Going to bed." << nl;
    else {
        for (int i = 0; i < num; i++) cout << ans[i] << " ";
    }

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}