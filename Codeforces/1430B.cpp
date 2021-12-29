#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
typedef long long ll;

const int MM = 2e5 + 5;
int n, k, a[MM];

void solve(int tc) {

    cin >> n >> k;
    ll mx = 0, idx = 1; priority_queue<int> pq;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] > mx) mx = a[i], idx = i;
    }
    for (int i = 1; i <= n; i++) {
        if (i == idx) continue;
        pq.push(a[i]);
    }
    for (int i = 1; i <= k; i++) {
        int cur = pq.top(); pq.pop();
        mx += cur;
    }
    cout << mx << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int tc = 1; cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}