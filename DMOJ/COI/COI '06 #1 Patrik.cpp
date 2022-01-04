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
#define rep(i,a,n) for (int i=a;i<n;i++)
#define rep1(i, a, n) for (int i=a; i<=n; i++)
#define per(i,a,n) for (int i=a-1;i>=n;i--)
#define per1(i,a,n) for (int i=a;i>=n;i--)
#define endl '\n'
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
const int MOD = 1e9 + 7;

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

const int MM = 500005;
int n, h[MM], freq[MM], top = -1; ll ans = 0;

void solve() {

    cin >> n;
    for (int i = 1; i <= n; i++) {
        int cur; cin >> cur;
        while (top >= 0 && cur > h[top]) {
            ans += freq[top]; top--;
        }
        if (top < 0) {
            ++top; h[top] = cur; freq[top] = 1;
        } else {
            if (cur == h[top]) {
                ans += freq[top];
                if (top >= 1) ans++;
                freq[top]++;
            } else {
                ans++;
                top++; h[top] = cur; freq[top] = 1;
            }
        }
    }
    cout << ans << nl;

}

int32_t main() {
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}