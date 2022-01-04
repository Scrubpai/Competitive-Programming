#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
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

ll ans, bit[3001][3001]; ll N, K; ll arr[3001][3001];

void update(int x, int y, ll v) {
    for (int i=x; i<=N; i+=i&-i) {
        if (i>x+K) break;
        for (int j=y; j<=N; j+=j&-j) {
            if (j>y+K) break;
            bit[i][j] = max(bit[i][j], v);
        }
    }
}
ll query(int x, int y) {
    ll ret = 0;
    for (int i=x; i>=1; i-=i&-i) {
        if (i<x-K) break;
        for (int j=y; j>=1; j-=j&-j) {
            if (j<y-K) break;
            ret = max(ret, bit[i][j]);
        }
    }
    return ret;
}

void solve() {

    cin >> N >> K;
    for (int i=1; i<=N; i++) {
        for (int j=N-i+1; j<=N; j++) {
            cin >> arr[i][j];
        }
    }
    for (int k=N; k>=1; k--) {
        int i=N; int j=k;
        while (i>=k) {
            update(i, j, arr[i][j]);
            if (i+K-1<=N) ans += query(i+K-1, j);
            i--; j++;
        }
    }
    cout << ans << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}