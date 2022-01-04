#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define nl '\n'
int N, R, E, C1, V1, CA, CB, CM, VA, VB, VM; priority_queue<int> pq[2005]; ll dp[2005];
void solve(int tc) {
    cin >> N >> R;
    ll add = 0;
    for (int i = 1; i <= N; i++) {
        cin >> E >> C1 >> V1 >> CA >> CB >> CM >> VA >> VB >> VM;
        if (C1 == 0) add += V1;
        else if (C1 <= R) pq[C1].push(V1);
        ll curC = C1, curV = V1;
        for (int j = 2; j <= E; j++) {
            curC = (1ll * curC * CA + 1ll * CB) % CM;
            curV = (1ll * curV * VA + 1ll * VB) % VM;
            if (curC == 0) add += curV;
            else if (curC <= R) pq[curC].push(curV);
        }
    }
    for (int w = 1; w <= R; w++) {
        for (int j = 1; j * w <= R; j++) {
            if (pq[w].empty()) break;
            ll v = pq[w].top(); pq[w].pop();
            for (int k = R; k >= w; k--) dp[k] = max(dp[k], dp[k-w] + v);
        }
    }
    cout << dp[R] + add << nl;
}
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}