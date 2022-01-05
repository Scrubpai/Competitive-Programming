#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
typedef long long ll;

const int MM = 1e6 + 5;
int n, d, p; vector<int> t[MM]; priority_queue<int> pq; ll ans;

void solve(int tc) {

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> d >> p;
        if (d > n) { pq.push(p); continue; }
        t[d].push_back(p);
    }
    for (int i = n; i >= 1; i--) {
        for (int x : t[i]) pq.push(x);
        if (!pq.empty()) { ans += pq.top(); pq.pop(); }
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