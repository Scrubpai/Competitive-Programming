#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
const int NM = (int)1e6;
typedef long long ll;
typedef pair<int, int> pi;
#define INF 0x3f
#define gl(x) getline(cin, (x))
#define sz(x) (int)(x.size())
#define af(x) x.begin(), x.end()
#define ms(x, y) memset(x, y, sizeof(x))
#define lb lower_bound
#define ub upper_bound
#define mpp make_pair
#define pb push_back
#define sz(a) sizeof(a)/sizeof(a[0])

int N, L, M; vector<char> adj[100]; vector<string> out; char c;

void rec(string str, int n) {
    if (str.size()>L) return;
    if (n==N) out.pb(str);
    else {
        for (int i=0; i<adj[n].size(); i++) {
            rec(str+adj[n][i], n+1);
        }
        if (str!="") rec(str, n+1);
    }
}

void solve() {

    cin >> N >> L;
    for (int i=0; i<N; i++) {
        cin >> M;
        for (int j=0; j<M; j++) {
            cin >> c;
            adj[i].pb(c);
        }
    }
    rec("", 0);
    sort(out.begin(), out.end());
    for (string x : out) cout << x << endl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}