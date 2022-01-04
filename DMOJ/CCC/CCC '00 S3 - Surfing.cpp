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

int n; unordered_map<string, int> mp; string str; vector<int> adj[10005]; bool vis[10005];

void bfs(int u, int v) {
    queue<int> q; ms(vis, 0); q.push(u); vis[u] = 1;
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (int v : adj[cur]) {
            if (!vis[v]) {
                vis[v] = 1; q.push(v);
            }
        }
    }
}

void solve(int tc) {

    cin >> n; getline(cin, str); int cnt = 0;
    for (int i = 0; i < n; i++) {
        getline(cin, str); string x = str;
        if (!mp.count(str)) mp[str] = ++cnt;
        getline(cin, str);
        while (str != "</HTML>") {
            int sz = str.size();
            for (int j = 0; j <= sz - 8; j++) {
                if (str.substr(j, 8) == "<A HREF=") {
                    string link = "";
                    for (j = j + 9; j ; j++) {
                        if (str[j] == '"') break;
                        else link += str[j];
                    }
                    if (!mp.count(link)) mp[link] = ++cnt;
                    cout << "Link from " << x << " to " << link << nl;
                    adj[mp[x]].push_back(mp[link]);
                }
            }
            getline(cin, str);
        }
    }
    string a, b; cin >> a >> b;
    while (a != "The" && b != "End") {
        int u = mp[a], v = mp[b];
        bfs(u, v);
        if (vis[v]) {
            cout << "Can surf from " << a << " to " << b << '.' << nl;
        } else {
            cout << "Can't surf from " << a << " to " << b << '.' << nl;
        }
        cin >> a >> b;
    }

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tc = 1;// cin >> tc;
    for (int t = 0; t < tc; t++) solve(t);

    return 0;
}