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

vector<ll> arr; ll N, A, B, m; ll dp[100];

void solve(int tc) {

    cin >> A >> B >> N;
    for (int i = 0; i < N; i++) { cin >> m; arr.push_back(m); }
    arr.push_back(0); arr.push_back(990); arr.push_back(1010); arr.push_back(1970);  arr.push_back(2030); arr.push_back(2940);
    arr.push_back(3060); arr.push_back(3930); arr.push_back(4060); arr.push_back(4970); arr.push_back(5030); arr.push_back(5990);
    arr.push_back(6010); arr.push_back(7000); sort(arr.begin(), arr.end());

    N = arr.size(); dp[0] = 1;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (arr[j] - arr[i] >= A && arr[j] - arr[i] <= B) dp[j] += dp[i];
        }
    }
    cout << dp[N-1] << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tc = 1; //cin >> tc;
    for (int t = 0; t < tc; t++) solve(t);

    return 0;
}