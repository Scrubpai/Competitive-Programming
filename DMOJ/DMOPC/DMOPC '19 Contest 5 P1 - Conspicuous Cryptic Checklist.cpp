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

int N, M, T; string s; unordered_map<string, int> mp;

void solve() {

    cin >> N >> M;
    for (int i=1; i<=N; i++) { cin >> s; mp[s] = i; }
    int cnt = 0;
    for (int i=1; i<=M; i++) {
        cin >> T; bool flag = true;
        for (int j=0; j<T; j++) { cin >> s; if (!mp.count(s)) flag = false; }
        if (flag) cnt++;
    }
    cout << cnt << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}