#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
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
const int MN = 200001;

double ans_x, ans_y = 0; double x, y;

void solve() {

    cin >> x >> y;
    if (x==0 && y==0) {
        ans_x = 125; ans_y = 125;
    } else if (x==0 && y>=125) {
        ans_x = 31250/y; ans_y = 0;
    } else if (x==0 && y<125) {
        ans_x = 31250/(250-y); ans_y = (ans_x*-1)+250;
    } else if (y==0 && x>=125) {
        ans_y = 31250/x; ans_x = 0;
    } else if (y==0 && x<125) {
        ans_y = 31250/(250-x); ans_x = -1*(ans_y-250);
    } else if (x<125 && y>=125) {
        ans_x = 250-(31250/y); ans_y = 0;
    } else if (x>=125 && y<125) {
        ans_x = 0; ans_y = 250-(31250/x);
    } else if (x==125 && y==125) {
        ans_x = 0; ans_y = 0;
    }

    printf("%.02f %.02f", ans_x, ans_y);

}

int32_t main() {
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}