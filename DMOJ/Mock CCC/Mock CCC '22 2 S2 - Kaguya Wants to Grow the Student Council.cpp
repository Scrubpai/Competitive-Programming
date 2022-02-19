#include <bits/stdc++.h>
using namespace std;
const int MM = 1e4+5;
int N, K, ans, in[MM], idx[MM][26]; string ballot[MM]; vector<int> adj[MM];
int dfs(int u) {
    int mx = 1;
    for (int v : adj[u]) {
        mx = max(mx, dfs(v)+1);
    }
    return mx;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N >> K;
    for (int i=0; i<N; i++) {
        cin >> ballot[i];
        for (int j=0; j<K; j++) {
            idx[i][ballot[i][j]-'A'] = j;
        }
    }
    for (int i=0; i<K; i++) {
        for (int j=0; j<K; j++) {
            if (i==j) continue;
            bool flag = 1;
            for (int k=0; k<N; k++) {
                if (idx[k][i] >= idx[k][j]) { flag = 0; break; }
            }
            if (flag) {
                adj[i].push_back(j), in[j]++;
            }
        }
    }
    for (int i=0; i<K; i++) {
        if (!in[i]) {
            ans = max(ans, dfs(i));
        }
    }
    cout << ans << '\n';
}