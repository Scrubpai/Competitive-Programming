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
//#define sz(a) sizeof(a)/sizeof(a[0])
//#define AUT auto
//#define f first
//#define s second
//coordinate compression:sort(val.begin(), val.end());
//		val.resize(unique(val.begin(), val.end()) - val.begin());
#define nl '\n'
typedef unsigned long long ull;
const int MOD = 10;

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
int T, n, a[MM], freq[MM], tmp[MM];

bool check(int d) {
    priority_queue<pii> pq; deque<pii> need;
    for (int i = 1; i <= n; i++) { tmp[i] = freq[i]; if (tmp[i]) pq.push({tmp[i], i}); }
    for (int i = 1; i <= n; i++) { //arrange the elements
        while (!need.empty() && need.front().first <= i - d - 1) { pq.push({tmp[need.front().second], need.front().second}); need.pop_front(); }
        if (pq.empty()) return 0;
        pii cur = pq.top(); pq.pop(); tmp[cur.second]--;
        if (tmp[cur.second]) need.push_back({i, cur.second});
    }
    return 1;
}

void solve() {

    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; i++) freq[i] = 0;
        for (int i = 1; i <= n; i++) { cin >> a[i]; freq[a[i]]++; }
        int lo = 0, hi = n - 2; int ans = 0;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (check(mid)) { ans = max(ans, mid); lo = mid + 1; }
            else hi = mid - 1;
        }
        cout << ans << nl;
    }

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}