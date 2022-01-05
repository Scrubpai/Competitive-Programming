#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 100001;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;
#define endl '\n'
#define INF 0x3f3f3f3f
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
#define f first
#define s second
#define nl '\n'

string s; int N, K; double a1, a2, b1, b2; int a[MAXN][101];

void solve() {

    cin >> N >> K >> a1 >> a2 >> b1 >> b2; int n=1;
    for (int i=1; i<=N; i++) a[0][i] = i;

    for (; n<=K; n++) {
        for (int i=1; i<=N; i++) { a[n][i] = a[n-1][i];  }
        for (int i=a1, j=a2; i<j; i++, j--) swap(a[n][i], a[n][j]);
        for (int i=b1, j=b2; i<j; i++, j--) swap(a[n][i], a[n][j]);

        bool flag = true;
        for (int i=1; i<=N; i++) if (a[n][i]!=a[0][i]) { flag = false; break; }
        if (flag) break;
    }
    if (n!=K) K%=n;

    for (int i=1; i<=N; i++) {
        cout << a[K][i] << endl;
    }

}

int32_t main() {
  //  ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}