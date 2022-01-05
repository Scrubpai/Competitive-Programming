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
//#define sz(a) sizeof(a)/sizeof(a[0])
//#define AUT auto
#define f first
#define s second
#define nl '\n'
const int MN = 1000000;

int h, m, s; bool vis[10]; string str; int dif = INF;

bool check(int hr, int mn, int sc) {
    for (int i=0; i<2; i++) { if (!vis[hr%10]) return false; hr/=10; }
    for (int i=0; i<2; i++) { if (!vis[mn%10]) return false; mn/=10; }
    for (int i=0; i<2; i++) { if (!vis[sc%10]) return false; sc/=10; }
    return true;
}

void solve() {

    scanf("%d:%d:%d", &h, &m, &s);
    cin >> str; for (int i=0; i<str.size(); i++) { int x = str[i]-'0'; vis[x] = true; }
   // if (str.size()==10) { printf("%02d:%02d:%02d", h, m, s); }

    int t = h*3600 + m*60 + s;

    int ans_h = 0, ans_m = 0, ans_s = 0;
    for (int i=0; i<100; i++) {
        for (int j=0; j<100; j++) {
            for (int k=0; k<100; k++) {
                if (check(i,j,k)) {
                    int cur_time = i*3600 + j*60 + k;
                    if (abs(t-cur_time)<dif) {
                        dif = abs(t-cur_time); ans_h = i; ans_m = j; ans_s = k;
                    }
                }
            }
        }
    }

    printf("%02d:%02d:%02d", ans_h, ans_m, ans_s);

}

int32_t main() {
    //ios_base::sync_with_stdio(false);
  //  cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}