#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define nl '\n'

const int MM = 1e6 + 5;
int n; unordered_map<int, ll> dp;
ll f(int w) {
    if (w <= 2) return 1;
    if (dp[w] > 0) return dp[w];
    ll tmp = 0, v = sqrt(w), last = v;
    for (int weight = v; weight >= 1; weight--) {
        ll num = w/weight - last;
        tmp += 1ll * num * f(weight);
        last = w/weight;
    }
    for (int branches = 2; branches <= v; branches++) {
        tmp += f(w/branches);
    }
    return dp[w] = tmp;
}

void solve(int tc) {

    cin >> n;
    cout << f(n) << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}