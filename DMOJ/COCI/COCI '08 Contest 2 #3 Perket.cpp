#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pi;
#define endl '\n'
#define INF 0x3f3f3f3f // for int
#define LL_INF 0x3f3f3f3f3f3f3f3f // for ll
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
const int MN = 1000000;
int N; pi a[11]; ll s, b; ll ans = INF;

void rec(int cur_idx, pi val) {
    if (cur_idx>1) {
        ans = min(ans, abs(val.s-val.f));
    }
    for (int i=cur_idx; i<=N; i++) {
        rec(i+1, {a[i].f*val.f, a[i].s+val.s});
    }
}

void solve() {

    cin >> N;
    for (int i=1; i<=N; i++) {
        cin >> s >> b; a[i] = {s,b};
    }

    rec(1, {1,0});
    cout << ans << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}