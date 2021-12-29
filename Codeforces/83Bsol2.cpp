#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5 + 5;
typedef long long ll;
#define nl '\n'
int n, a[MM], sorted[MM]; ll k;
void solve(int tc) {
    cin >> n >> k;
    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sorted[i] = a[i];
        sum += a[i];
    }
    if (sum < k) { cout << -1 << nl; return; }
    sort(sorted + 1, sorted + 1 + n);
    ll prev = 0;
    for (int s = 1; s <= n; s++) {
        int val = sorted[s];
        if (k < (ll)(val - prev) * 1ll*(n - s + 1)) {
            ll div = k / (n - s + 1);
            prev += div;
            k -= (1ll*div*(n-s+1));
            break;
        }
        k -= (ll)(val - prev) * 1ll*(n - s + 1);
        prev = val;
    }
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (a[i] > prev) q.push(i);
    }
    while (k-- > 0) {
        int top = q.front(); q.pop();
        if (a[top] - 1 > prev) q.push(top);
    }
    while (!q.empty()) {
        int top = q.front(); q.pop();
        cout << top << ' ';
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}