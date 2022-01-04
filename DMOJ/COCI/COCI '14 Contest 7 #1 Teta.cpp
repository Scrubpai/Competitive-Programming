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

int K; int cost[21]; int Meal; int M[5]; int T; int freq[21]; int cnt[21]; int mx = 0;

void solve() {

    cin >> K;
    for (int i=1; i<=K; i++) cin >> cost[i];
    cin >> Meal;
    for (int i=1; i<=4; i++) cin >> M[i];
    cin >> T;
    for (int i=1, x; i<=T; i++) {
        cin >> x; freq[x]++;
        if (x==M[1] || x==M[2] || x==M[3] || x==M[4]) { cnt[x]++; mx = max(mx, cnt[x]); }
    }

    int tmp1 = 0; int tot = numeric_limits<int>::max();

    for (int i=1; i<=K; i++) {
        if (cnt[i]==0) {
            tmp1 += (freq[i] * cost[i]);
        }
    }

    for (int i=0; i<=mx; i++) {
        int tmp2 = (Meal*i); int tmp3 = 0;
        for (int j=1; j<=K; j++) {
            if (cnt[j]>i) {
                tmp3 += ((cnt[j]-i)*cost[j]);
            }
        }
        int x = tmp2+tmp3;
        tot = min(tot, x);
    }

    int ans = tmp1 + tot;
    cout << ans << endl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}