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
struct P {
    int x, y;
};
bool cmp(P a, P b) {
    if (a.x != b.x) return a.x < b.x;
    else return a.y < b.y;
}
int N; P pts[MM]; stack<int> st;

void solve(int tc) {

    cin >> N;
    for (int i = 1, x, y; i <= N; i++) {
        cin >> x >> y;
        pts[i] = {x, y};
    }
    sort(pts + 1, pts + 1 + N, cmp);
    for (int i = 1; i <= N; i++) {
        int mn = pts[i].y;
        while (!st.empty() && st.top() <= pts[i].y) {
            mn = min(mn, st.top());
            st.pop();
        }
        st.push(mn);
    }
    cout << st.size() << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);

    return 0;
}