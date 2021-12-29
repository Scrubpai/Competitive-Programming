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
#define ms(x, y) memset(x, y, sizeof(x))
//coordinate compression:sort(val.begin(), val.end());
//		val.resize(unique(val.begin(), val.end()) - val.begin());
#define nl '\n'
typedef unsigned long long ull;
const lld pi = 3.14159265358979323846;
const int MOD = 1e9 + 7;

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

int n, in[26]; bool vis[26]; string name[105]; vector<int> adj[105]; unordered_set<int> st; queue<int> ans;

void solve(int tc) {

    cin >> n >> name[1];
    for (int i = 2; i <= n; i++) {
        cin >> name[i];
        for (int k = i - 1; k >= 1; k--) {
            int sz = min(name[k].size(), name[i].size());
            for (int j = 0; j < sz; j++) {
                if (name[i][j] != name[k][j]) {
                    int u = name[k][j] - 'a', v = name[i][j] - 'a';
                    adj[u].push_back(v); in[v]++; st.insert(u); st.insert(v);
                    break;
                }
            }
        }
    }
    for (int i = 2; i <= n; i++) {
        for (int j = i - 1; j >= 1; j--) {
            int sz1 = name[i].size(), sz2 = name[j].size();
            if (sz1 >= sz2) continue;
            if (name[j].substr(0, sz1) == name[i]) { cout << "Impossible" << nl; return; }
        }
    }
    queue<int> q; int cnt = 0;
    for (int i = 0; i < 26; i++) {
        if (st.count(i) && !in[i]) { q.push(i); ans.push(i); vis[i] = 1; cnt++; }
    }
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (int v : adj[cur]) {
            in[v]--;
            if (!in[v]) {
                vis[v] = 1; q.push(v); ans.push(v); cnt++;
            }
        }
    }
    if (cnt != st.size()) { cout << "Impossible" << nl; return; }
    while (!ans.empty()) {
        int x = ans.front(); ans.pop();
        char ch = x + 'a';
        cout << ch;
    }
    for (int i = 0; i < 26; i++) {
        if (!vis[i]) {
            char ch = i + 'a';
            cout << ch;
        }
    }

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);

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