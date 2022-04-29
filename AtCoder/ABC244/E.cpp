#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int N, M, K, S, T, X, dp[2001][2001][2]; vector<int> adj[2001];
int fun(int u, int k, int e) {
    if (k==1) {
        if (u==S && e==0) return 1;
        else return 0;
    }
    if (dp[u][k][e] != -1) return dp[u][k][e];
    int &ret = dp[u][k][e], add = (u==X?1:0); ret = 0;
    for (int v: adj[u]) {
        ret = (ret + fun(v, k-1, e^add)) % mod;
    }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M >> K >> S >> T >> X;
    for (int i=1, u, v; i<=M; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    memset(dp, -1, sizeof(dp));
    cout << fun(T, K+1, 0) << '\n';
}