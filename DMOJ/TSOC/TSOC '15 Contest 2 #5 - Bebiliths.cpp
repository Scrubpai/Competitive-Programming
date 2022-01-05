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
const int MOD = 1000000000;
ll gcd(ll a, ll b){return b == 0 ? a : gcd(b, a % b);}
ll lcm(ll a, ll b){return a*b/gcd(a,b);}
ll pwmd(ll b, ll exp) {
    ll ret = 1;
    while (exp>0) {
        if (exp%2==1) ret = (ret*b)%MOD;
        exp/=2;
        b = (b*b)%MOD;
    }
    return ret;
}


struct Q {
    int B, D, C, idx;
};
int S, N, q;

bool cmp(Q a, Q b) {
    if (a.B != b.B) return a.B > b.B;
    else {
        if (a.B < S && a.D != b.D) return a.D > b.D;
        else if (a.B >= S && a.C != b.C) return a.C > b.C;
        else return a.idx < b.idx;
    }
}
Q arr[50005];

void solve() {

    cin >> S >> N;
    for (int i = 1; i <= N; i++) {
        int b, d, c; cin >> b >> d >> c; arr[i]  = {b, d, c, i};
    }
    sort(arr + 1, arr + 1 + N, cmp);
    cin >> q;
    while (q--) {
        int pos; cin >> pos;
        cout << arr[pos].idx << nl;
    }

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}