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

string a, b, str; int x; char possible[5][4];

void solve(int tc) {

    cin >> a >> b >> x; int tmp = 0;
    for (int i = 0; i < 9; i += 2) {
        possible[tmp][0] = min(a[i], b[i]);;
        possible[tmp][1] = min(a[i], b[i+1]);
        possible[tmp][2] = min(a[i+1], b[i]);
        possible[tmp][3] = min(a[i+1], b[i+1]);
        tmp++;
    }
    while (x--) {
        cin >> str; bool flag = 1;
        for (int i = 0; i < str.size(); i++) {
            if (str[i] != possible[i][0] && str[i] != possible[i][1] && str[i] != possible[i][2] && str[i] != possible[i][3]) { flag = 0; break; }
        }
        if (!flag) cout << "Not their baby!" << nl;
        else cout << "Possible baby." << nl;
    }

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tc = 1; //cin >> tc;
    for (int t = 0; t < tc; t++) solve(t);

    return 0;
}