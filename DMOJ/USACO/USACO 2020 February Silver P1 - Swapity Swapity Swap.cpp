#include <bits/stdc++.h>
using namespace std;
const int NM = (int)1e5 + 5;
typedef long long ll;
typedef pair<int, int> pi;
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
#define f first
#define s second
#define nl '\n'

int N, M, K; int l[101], r[101]; int nxt[NM], ans[NM]; bool vis[NM]; vector<int> cycle;

void solve() {

    cin >> N >> M >> K;
    for (int i=1; i<=M; i++) { cin >> l[i] >> r[i]; }
    for (int i=1; i<=N; i++) {
        nxt[i] = i;
        for (int j=1; j<=M; j++) {
            if (nxt[i]>=l[j] && nxt[i]<=r[j]) nxt[i] = l[j]+r[j]-nxt[i];
        }
    }
    for (int i=1; i<=N; i++) {
        if (vis[i]) continue;
        cycle.clear(); int cur = i;
        while (cycle.empty() || cur!=i) {
            cycle.pb(cur); vis[cur] = true; cur = nxt[cur];
        }
        for (int j=0; j<cycle.size(); j++) {
            int pos = cycle[((K%cycle.size())+j)%cycle.size()];
            ans[pos] = cycle[j];
        }
    }
    for (int i=1; i<=N; i++) cout << ans[i] << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}