#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5 + 5, mod = 998244353;
#define nl '\n'
int n, k, a[MM], b[MM], posA[MM], posB[MM];
void solve(int tc) {
    cin >> n >> k;
    //posB[i]: the position of element a[i] in array b[]
    //posA[i]: the position of element a[i] in array a[]
    for (int i = 1; i <= n; i++) { cin >> a[i]; posA[a[i]] = i; }
    memset(posB, -1, sizeof(posB));
    for (int i = 1; i <= k; i++) {
        cin >> b[i];
        posB[posA[b[i]]] = i;
    }
    int ans = 1;
    for (int i = 1; i <= n; i++) {
        if (posB[i] == -1) continue;
        int cnt = 0;
        if (i > 1 && posB[i-1] < posB[i]) cnt++;
        if (i < n && posB[i+1] < posB[i]) cnt++;
        ans = (ans * cnt) % mod;
    }
    cout << ans << nl;
}
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc = 1; cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}