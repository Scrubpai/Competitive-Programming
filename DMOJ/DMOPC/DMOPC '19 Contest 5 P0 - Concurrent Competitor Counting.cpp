#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
const long long MAXN = numeric_limits<long long>::max();
typedef long long ll;
#define INF 0x3f3f3f3f
#define gl(x) getline(cin, (x))
#define sz(x) (int)(x.size())
#define af(x) x.begin(), x.end();
#define ms(x, y) memset(x, y, sizeof(x))
#define lb lower_bound
#define ub upper_bound
#define mp make_pair
#define pb push_back
#define sz(a) sizeof(a)/sizeof(a[0])

int N, C, x; string s;

void solve() {

    cin >> N >> C;
    for (int i=0; i<N; i++) {
        cin >> s >> x;
        if (x > C) cout << s << " will advance";
        else cout << s << " will not advance";

        cout << endl;
    }

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}