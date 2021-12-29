#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5 + 5;
typedef long long ll;
#define nl '\n'
int n, a[MM], tmp; ll k;
bool check(int v) {
    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += min(a[i], v);
    }
    return sum <= k;
}
void bsearch() {
    int lo = 1, hi = 1e9;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (check(mid)) tmp = max(tmp, mid), lo = mid + 1;
        else hi = mid - 1;
    }
}
void solve(int tc) {
    cin >> n >> k;
    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    if (sum < k) { cout << -1 << nl; return; }
    bsearch();
    for (int i = 1; i <= n; i++) {
        k -= min(a[i], tmp);
    }
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (a[i] > tmp) q.push(i);
    }
    while (k-- > 0) {
        int top = q.front(); q.pop();
        if (a[top] - 1 > tmp) q.push(top);
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