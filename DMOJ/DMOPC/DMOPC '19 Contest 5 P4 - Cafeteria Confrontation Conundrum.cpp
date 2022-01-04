#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
const long long MAXN = (int)1e5 + 1;
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

int N, Q; ll m[MAXN]; ll p, c; int x;

void solve() {

    cin >> N >> Q;

    for (int i=1; i<=N; i++) {
        cin >> m[i];
    }

    for (int i=1; i<=N; i++) {
        cin >> x;
        if (x!=0) {
            m[i] += m[x];
        }
    }

    for (int i=1; i<=Q; i++) {
        cin >> p >> c;
        ll need = c-p; bool flag = true;
        if (need<=0) { cout << -1 << endl; continue; }
        for (int i=1; i<=N; i++) {
            if (m[i]>=need) {
                cout << i << endl; flag = false; break;
            }
        }
        if (flag) cout << -1 << endl;
    }


}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}