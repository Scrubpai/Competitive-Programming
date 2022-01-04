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
//#define sz(a) sizeof(a)/sizeof(a[0])
//#define AUT auto
#define f first
#define s second
#define nl '\n'

int N, M; int8_t psa[10005][10005];

void solve() {

    cin >> N >> M;
    for (int t=0,x,y,w,h; t<M; t++) {
        cin >> x >> y >> w >> h;
        psa[x+1][y+1]++; psa[x+w+1][y+1]--; psa[x+w+1][y+h+1]++; psa[x+1][y+h+1]--;
    }
    int cnt = 0;
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            psa[i][j] = psa[i][j] + psa[i-1][j] + psa[i][j-1] - psa[i-1][j-1];
            if (psa[i][j] & 1) cnt++;
        }
    }
    cout << cnt << nl;

}

int32_t main() {
  //  ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}