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

int n; string str; string a[8] = {"Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue"};
string need[8][2];

void solve(int tc) {

    cin >> n; sort(a, a + 8); getline(cin, str);
    for (int i = 0; i < n; i++) {
        getline(cin, str); int idx = -1;
        for (int j = 0; j < str.size(); j++) {
            if (str[j] == ' ' && idx == -1) {
                string tmp = str.substr(0, j); need[i][0] = tmp; idx = j;
            } else if (str[j] == ' ') idx = j;
        }
        string tmp = str.substr(idx + 1); need[i][1] = tmp;
    }
    do {
        bool flag = 1;
        for (int i = 0; i < n; i++) {
            string x = need[i][0], y = need[i][1]; bool tmp = 0;
            for (int j = 0; j < 8; j++) {
                if (a[j] == x) {
                    if (j < 7 && a[j+1] == y) tmp = 1;
                    if (j > 0 && a[j-1] == y) tmp = 1;
                }
            }
            if (!tmp) { flag = 0; break; }
        }
        if (flag) {
            for (int i = 0; i < 8; i++) cout << a[i] << nl;
            break;
        }
    } while (next_permutation(a, a + 8));

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tc = 1; //cin >> tc;
    for (int t = 0; t < tc; t++) solve(t);

    return 0;
}