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

int m, in[905]; priority_queue<int, vector<int>, greater<int>> pq; unordered_map<string, int> mp1; unordered_map<int, string> mp2; vector<int> adj[1805];

void solve(int tc) {

    cin >> m; int cnt = 0;
    for (int i = 1; i <= m; i++) {
        string a, b; cin >> a >> b;
        if (!mp1.count(a)) mp1[a] = ++cnt, mp2[cnt] = a;
        if (!mp1.count(b)) mp1[b] = ++cnt, mp2[cnt] = b;
        in[mp1[a]]++; adj[mp1[b]].push_back(mp1[a]);
    }
    for (int i = 1; i <= cnt; i++) {
        if (!in[i]) pq.push(i);
    }
    while (!pq.empty()) {
        int cur = pq.top(); pq.pop(); cout << mp2[cur] << nl;
        for (int v : adj[cur]) {
            in[v]--;
            if (!in[v]) pq.push(v);
        }
    }

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tc = 1; //cin >> tc;
    for (int t = 0; t < tc; t++) solve(t);

    return 0;
}