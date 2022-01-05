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
#define f first
#define s second
#define nl '\n'

ll N, M; ll dsu[MAXN]; ll sizee[MAXN]; int a; int b; vector<pi> graph(MAXN); ll ans[MAXN]; ll cur_ans;

int Find(int x) {
    if (dsu[x]==x) return x;
    else return dsu[x] = Find(dsu[x]);
}

void solve() {

    cin >> N >> M;

    for (int i=1; i<=M; i++) {
        cin >> a >> b;
        graph[i] = {a, b};
    }

    for (int i=1; i<=N; i++) {
        dsu[i] = i; sizee[i] = 1;
    }

    ans[M+1] = cur_ans = (N*(N-1))/2;

    for (int i=M; i>=1; i--) {
        int a = graph[i].first; int b = graph[i].second;
        int fa = Find(a); int fb = Find(b);
        ans[i] = cur_ans;
        if (fa!=fb) {
            dsu[fb] = fa;
            cur_ans -= (sizee[fb]*sizee[fa]);
            sizee[fa]+=sizee[fb]; sizee[fb] += sizee[fa];
        }
    }


    for (int i=1; i<=M; i++) {
        cout << ans[i] << endl;
    }

}

int32_t main() {
  //  ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}