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
const int MOD = 1000000000;

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
ll m, n, odd[3005][3005], even[3005][3005], X; int R, C, R1, C1, R2, C2;

void updateodd(int r, int c, ll x) {
    for (int i = r; i <= m; i += i&-i) {
        for (int j = c; j <= n; j += j&-j) {
            odd[i][j] += x;
        }
    }
}

ll queryodd(int r, int c) {
    ll sum = 0;
    for (int i = r; i >= 1; i -= i&-i) {
        for (int j = c; j >= 1; j -= j&-j) {
            sum += odd[i][j];
        }
    }
    return sum;
}

void updateeven(int r, int c, ll x) {
    for (int i = r; i <= m; i += i&-i) {
        for (int j = c; j <= n; j += j&-j) {
            even[i][j] += x;
        }
    }
}

ll queryeven(int r, int c) {
    ll sum = 0;
    for (int i = r; i >= 1; i -= i&-i) {
        for (int j = c; j >= 1; j -= j&-j) {
            sum += even[i][j];
        }
    }
    return sum;
}

void solve(int tc) {

    cin >> m >> n;
    while (1) {
        cin >> R >> C >> X;
        if (R == 0) break;
        if ((R + C) % 2 == 1) updateodd(R, C, X);
        else updateeven(R, C, X);
    }
    while (1) {
        
        cin >> R1 >> C1 >> R2 >> C2;
        if (R1 == 0) break;
        if ((R1 + C1) % 2 == 1) {
            ll add = queryodd(R2, C2) - queryodd(R2, C1-1) - queryodd(R1-1, C2) + queryodd(R1-1, C1-1);
            ll sub = queryeven(R2, C2) - queryeven(R2, C1-1) - queryeven(R1-1, C2) + queryeven(R1-1, C1-1);
            cout << add - sub << nl;
        } else {
            ll add = queryeven(R2, C2) - queryeven(R2, C1-1) - queryeven(R1-1, C2) + queryeven(R1-1, C1-1);
            ll sub = queryodd(R2, C2) - queryodd(R2, C1-1) - queryodd(R1-1, C2) + queryodd(R1-1, C1-1);
            cout << add - sub << nl;
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