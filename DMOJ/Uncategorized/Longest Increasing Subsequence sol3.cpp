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
const int MN = 1000000;

int N; int a[MN+1]; int dp[MN+1]; int ans = 1;

int search(int lo, int hi, int key) {
    while (lo<hi) {
        int mid = (lo+hi)/2;
        if (dp[mid]>=key) hi = mid;
        else lo = mid+1;
    }
    return hi;
}

void solve() {

    cin >> N;
    for (int i=0; i<N; i++) { cin >> a[i]; } dp[0] = a[0];

    for (int i=1; i<N; i++) {
        if (a[i]<dp[0]) dp[0] = a[i];
        else if (a[i]>dp[ans-1]) dp[ans++] = a[i];
        else dp[search(0, ans-1, a[i])] = a[i];
    }

    cout << ans << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}