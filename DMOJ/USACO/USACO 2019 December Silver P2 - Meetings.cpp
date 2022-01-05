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

const int MM = 5e4 + 5;

struct C {
    ll w, x, d;
};
bool cmp(C a, C b) {
    return a.x < b.x;
}

int L, N; C cows[MM]; vector<pii> a; ll sum;

void solve(int tc) {

    cin >> N >> L;
    for (int i = 0; i < N; i++) {
        cin >> cows[i].w >> cows[i].x >> cows[i].d;
        sum += 1LL * cows[i].w;
        if (cows[i].d == -1) {
            a.push_back({cows[i].x, -1});
        } else {
            a.push_back({L - cows[i].x, 1});
        }
    }
    sort(cows, cows + N, cmp); sort(a.begin(), a.end());
    ll curw = 0, lft = 0, rit = N - 1, T = 0;
    for (int i = 0; i < N; i++) {
        if (a[i].second == -1) {
            curw += 1LL * cows[lft].w;
            lft++;
        } else {
            curw += 1LL * cows[rit].w;
            rit--;
        }
        if (curw * 1LL * 2 >= sum) {
            T = 1LL * a[i].first;
            break;
        }
    }
    ll ans = 0; queue<int> q;
    for (int j = 0; j < N; j++) {
        if (cows[j].d == -1) {
            while (!q.empty() && 1LL * q.front() + 1LL * 2 * T < cows[j].x) q.pop();
            ans += 1LL * q.size();
        } else {
            q.push(cows[j].x);
        }
    }
    cout << ans << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tc = 1; //cin >> tc;
    for (int t = 0; t < tc; t++) solve(t);

    return 0;
}