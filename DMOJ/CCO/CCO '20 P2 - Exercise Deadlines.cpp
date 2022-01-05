#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
typedef long long ll;

const int MM = 2e5 + 5;
int n, p[MM], bit[MM]; vector<int> t[MM]; priority_queue<int> q; ll ans;

int query(int p) {
    int ret = 0;
    for (; p >= 1; p -= p&-p) ret += bit[p];
    return ret;
}

void update(int p) {
    for (; p <= n; p += p&-p) bit[p]++;
}

void solve(int tc) {

    cin >> n;
    for (int i = 1, d; i <= n; i++) {
        cin >> d;
        t[d].push_back(i);
    }
    for (int i = n; i >= 1; i--) {
        for (int x : t[i]) q.push(x);
        if (q.empty()) { cout << - 1 << nl; return; }
        p[i] = q.top(); q.pop();
    }
    for (int i = 1; i <= n; i++) {
        ans += (i - 1) - query(p[i]);
        update(p[i]);
    }
    cout << ans << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int tc = 1;// cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}