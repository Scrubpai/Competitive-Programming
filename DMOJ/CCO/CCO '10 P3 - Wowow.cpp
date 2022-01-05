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

struct Q {
    char c; int X, R;
};

const int MM = 1e6 + 5;
int N, bit[MM], X, R, K, score[MM]; unordered_map<int, int> mp; char ch; vector<int> v; vector<Q> queries;

void update(int p, int v) {
    for (; p <= MM - 5; p += p&-p) bit[p] += v;
}

int query(int p) {
    int ret = 0;
    for (; p >= 1; p -= p&-p) ret += bit[p];
    return ret;
}

void solve(int tc) {

    cin >> N; int cnt = 0; v.push_back(0);
    while (N--) {
        cin >> ch;
        if (ch == 'N') {
            cin >> X >> R; v.push_back(R);
            queries.push_back({ch, X, R});
        } else if (ch == 'M') {
            cin >> X >> R; v.push_back(R);
            queries.push_back({ch, X, R});
        } else {
            cin >> K;
            queries.push_back({ch, K, 0});
        }
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < queries.size(); i++) {
        ch = queries[i].c;
        if (ch == 'N') {
            X = queries[i].X; R = lower_bound(v.begin(), v.end(), queries[i].R) - v.begin();
            mp[R] = X; score[X] = R; cnt++;
            update(R, 1);
        } else if (ch == 'M') {
            X = queries[i].X; R = lower_bound(v.begin(), v.end(), queries[i].R) - v.begin();
            update(score[X], -1); mp[R] = X; score[X] = R; update(R, 1);
        } else {
            K = queries[i].X; int lo = 1, hi = MM - 2, ans = INF;
            while (lo <= hi) {
                int mid = (lo + hi) / 2, val = cnt - query(mid) + 1;
                if (val <= K) {
                    if (val < K) { hi = mid - 1; }
                    else { hi = mid - 1; ans = min(ans, mid); }
                }
                else { lo = mid + 1; }
            }
            cout << mp[ans] << nl;
        }
    }

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);

    return 0;
}