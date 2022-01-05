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

const int MM = 2005;
double H, D, E, psa[MM]; double A[5], S[5];

void solve() {

    cin >> H >> D >> E;
    for (int i = 0; i < D; i++) {
        cin >> A[i] >> S[i];
        A[i] /= 100;
    }
    for (int i = 0; i < E; i++) {
        int T, L, X; cin >> T >> L >> X;
        psa[T+1]+=X; psa[T+L+1]-=X;
    }
    for (int i = 1; i <= 1010; i++) psa[i] += psa[i-1];
    for (int i = 1; i <= 1010; i++) {
        double cur_dmg = psa[i]; double add = cur_dmg;
        for (int j = 0; j < D; j++) {
            add = min(add, (1.0 - A[j]) * max(0.0, cur_dmg - S[j]));
        }
        H -= add;
    }
    if (H <= 0) cout << "DO A BARREL ROLL!" << nl;
    else printf("%.2f\n", H);

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}