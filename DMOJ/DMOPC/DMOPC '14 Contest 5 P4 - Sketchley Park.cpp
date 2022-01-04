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
#define mpp make_pair
#define pb push_back
#define AUT auto
#define nl '\n'
typedef unsigned long long ull;
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

const int MM = 1e5 + 5;
string msg, str, tmp; int n, m, a[10]; vector<int> v;
unordered_map<char, int> mp;
string need = "HAILHYDRA";

void solve() {

    cin >> msg >> n; tmp = msg; m = need.size(); int sz = msg.size();
    a[0] = 7; a[1] = 0; a[2] = 8; a[3] = 11; a[4] = 7; a[5] = 24; a[6] = 3; a[7] = 17; a[8] = 0;
    for (int i = 0; i <= sz - m; i++) {
        if (msg[i] == msg[i+4] && msg[i+1] == msg[i+8]) v.push_back(i);
    }
    if (sz < m || v.empty()) { cout << "KeyNotFoundError" << nl; return; }
    for (int i = 1; i <= n; i++) {
        cin >> str; bool flag = 0;
        for (int j = 0; j < 26; j++) mp[str[j]] = j;
        for (int idx : v) {
            int cur = 0;
            for (int j = idx; j < idx + 9; j++) {
                if (mp[msg[j]] != a[cur++]) break;
            }
            if (cur == 9) { flag = 1; break; }
        }
        if (flag) {
            for (int j = 0; j < sz; j++) msg[j] = mp[msg[j]] + 'A';
            cout << msg << nl; return;
        }
    }
    cout << "KeyNotFoundError" << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}