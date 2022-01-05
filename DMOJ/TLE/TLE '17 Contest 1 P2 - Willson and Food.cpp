#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
const int NM = (int)1e5 + 1;
typedef long long ll;
typedef pair<int, int> pi;
#define INF 0x3f
#define gl(x) getline(cin, (x))
#define sz(x) (int)(x.size())
#define af(x) x.begin(), x.end();
#define ms(x, y) memset(x, y, sizeof(x))
#define lb lower_bound
#define ub upper_bound
#define mpp make_pair
#define pb push_back
#define sz(a) sizeof(a)/sizeof(a[0])

int F, N; unordered_map<string, int> mp; vector<pi> a; string s;

void solve() {

    cin >> F;
    for (int i=0, x; i<F; i++) {
        cin >> s >> x; mp[s] = x;
    }

    cin >> N;
    for (int i=1, x; i<=N; i++) {
        cin >> s >> x; a.pb({x, mp[s]});
    }
    sort(a.begin(), a.end());

    int cnt = 0; int energy = 0; int location = 0;
    for (pi item : a) {
        if (item.first - location > max(energy, 0)) break;

        energy += (item.second - (item.first - location));
        cnt++; location = item.first;
    }

    cout << cnt << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}