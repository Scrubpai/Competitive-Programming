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

const int MM = 1e5 + 5;
struct B {
    int l, w, h; ll p; int indx;
};
bool cmp(B a, B b) {
    if (a.l != b.l) return a.l < b.l;
    else if (a.w != b.w) return a.w < b.w;
    else return a.h < b.h;
}
int N, L, W, H; ll P, bit[5005][5005], dp[MM], pre[MM], block[MM]; B arr[MM];

int query(int w, int h) {
    ll idx = 0, mx = 0;
    for (int i = w; i >= 1; i -= i&-i) {
        for (int j = h; j >= 1; j -= j&-j) {
            if (dp[bit[i][j]] > mx) {
                mx = dp[bit[i][j]]; idx = bit[i][j];
            }
        }
    }
    return idx;
}

void update(int w, int h, int idx) {
    for (int i = w; i <= 5000; i += i&-i) {
        for (int j = h; j <= 5000; j += j&-j) {
            if (dp[bit[i][j]] < dp[idx]) {
                bit[i][j] = idx;
            }
        }
    }
}

void solve(int tc) {

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> L >> W >> H >> P;
        if (L > W) swap(L, W);
        arr[i] = {L, W, H, P, i};
    }
    sort(arr + 1, arr + 1 + N, cmp);
    ll st = -1, mx = 0;
    for (int i = 1; i <= N; i++) {
        int p = query(arr[i].w, arr[i].h);
        dp[i] = dp[p] + arr[i].p; pre[i] = p; block[i] = arr[i].indx;
        if (dp[i] > mx) { mx = dp[i]; st = i; }
        update(arr[i].w, arr[i].h, i);
    }
    cout << mx << nl;
    int cnt = 0;
    for (int i = st; i != 0; i = pre[i]) cnt++;
    cout << cnt << nl;
    for (int i = st; i != 0; i = pre[i]) cout << block[i] << " ";
    cout << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);

    return 0;
}