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
#define mp make_pair
#define pb push_back
#define sz(a) sizeof(a)/sizeof(a[0])

string s;

void solve() {

    int ans = 0;
    for (int r=0; r<4; r++) {
        cin >> s;
        for (int c=0; c<4; c++) {
            char ch = s[c];
            if (ch=='.') continue;
            int dr = (int)(ch-'A')/4; int dc = (int)(ch-'A')%4;
            ans += (abs(r-dr) + abs(c-dc));
        }
    }

    cout << ans << endl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}