#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 100000;
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

int wait[101]; int M, X; char c; int msg[101]; bool vis[101];

void solve() {

    cin >> M; int t = 0; ms(msg, -1);
    for (int i=0, X; i<M; i++) {
        cin >> c >> X;
        if (c=='R') { msg[X] = t; vis[X] = true; }
        else if (c=='S') { wait[X] += t-msg[X]; vis[X] = false; }
        else { t += X-2; }
        t++;
    }
    for (int i=1; i<=100; i++) {
        if (msg[i]!=-1) {
            cout << i << " ";
            if (vis[i]) cout << -1 << endl;
            else cout << wait[i] << endl;
        }
    }

}

int32_t main() {
  //  ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}