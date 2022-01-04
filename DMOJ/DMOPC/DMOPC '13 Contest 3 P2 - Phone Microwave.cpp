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

int Y, M, D, h, m, s; int t;

void solve() {

    cin >> t;
    scanf("%d/%d/%d %d:%d:%d", &Y, &M, &D, &h, &m, &s);
    for (int i=1; i<=t; i++) {
        h--;
        if (h<0) {
            h+=24; D--;
            if (D<=0) {
                M--;
                if (M==4 || M==6 || M==9 || M==11) D+=30;
                else if (M==2) D+=28;
                else D+=31;
                if (M<=0) {
                    M+=12; Y--;
                }
            }
        }
    }
    printf("%d/%02d/%02d %02d:%02d:%02d", Y, M, D, h, m, s);

}

int32_t main() {
  //  ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}