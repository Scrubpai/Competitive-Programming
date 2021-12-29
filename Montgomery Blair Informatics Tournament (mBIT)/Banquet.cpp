#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define nl '\n'

const int MM = 1e5 + 5;
int n, a[MM], cnt[MM]; ll ans; bool vis[MM];

void solve (int tc) {

    cin >> n;
    for (int i = 1; i <= n; i++) { cin >> a[i]; cnt[i] = 1; }
    int l = 1;
    for (int i = 1; i <= n; i++) {
        while (cnt[i] < a[i]) {
            if (vis[l] || i == l) l++;
            else if (cnt[l] > 0) ans += abs(i - l), cnt[i]++, cnt[l]--, l++;
        }
        if (a[i] > 0) vis[i] = 1;
    }
    cout << ans << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}