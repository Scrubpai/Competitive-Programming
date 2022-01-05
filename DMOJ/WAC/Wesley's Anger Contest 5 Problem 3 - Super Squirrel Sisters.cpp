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

const int MM = 2e5 + 5;
int n, b[MM], freq[MM];

void solve() {

    cin >> n; ll ans = 0;
    for (int i = 1; i <= n; i++) cin >> b[i];
    for (int i = 1; i <= sqrt(n); i++) {
        int sz = i * i;
        if (sz > n) break;
        for (int j = 1; j <= n; j++) freq[j] = 0;
        int distinct = 0;
        for (int j = 1; j <= n; j++) {
            freq[b[j]]++;
            if (freq[b[j]] == i) distinct++;
            else if (freq[b[j]] != i && freq[b[j]] - 1 == i) distinct--;
            if (j > sz) {
                freq[b[j-sz]]--;
                if (freq[b[j-sz]] != i && freq[b[j-sz]] + 1 == i) distinct--;
                else if (freq[b[j-sz]] == i && freq[b[j-sz]] + 1 != i) distinct++;
            }
            if (j >= sz) {
                if (distinct == i) {
                    ans++;
                }
            }
        }
    }
    cout << ans << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}