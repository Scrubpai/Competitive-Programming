#include <bits/stdc++.h>
using namespace std;
const long long MAXN = (int)5e5 + 5;
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
#define sz(a) sizeof(a)/sizeof(a[0])
#define AUT auto
#define f first
#define s second
#define nl '\n'

int N, T; int dp[10001];

void solve() {

    cin >> N >> T;
    for (int i=0, Pp, Vp, Pa, Va, Pg, Vg; i<N; i++) {
        cin >> Pp >> Vp >> Pa >> Va >> Pg >> Vg; int mn = min(Pp, min(Pa, Pg));
        for (int j=T; j>=mn; j--) {
            if (j-Pp>=0) dp[j] = max(dp[j], dp[j-Pp]+Vp);
            if (j-Pa>=0) dp[j] = max(dp[j], dp[j-Pa]+Va);
            if (j-Pg>=0) dp[j] = max(dp[j], dp[j-Pg]+Vg);
        }
    }

    cout << dp[T] << endl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}