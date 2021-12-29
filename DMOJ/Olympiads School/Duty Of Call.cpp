#include <bits/stdc++.h>
using namespace std;
const int MM = 5e5+5;
int N, R, in[MM], team[MM]; vector<int> adj[MM];
void dfs(int u, int pa, int t) {
    for (int v : adj[u]) {
        if (v == pa || team[v] != -1) continue;
        team[v] = t^1;
        dfs(v, u, t^1);
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N >> R;
    for (int i=1, K; i<=N; i++) {
        cin >> K;
        for (int j=1, t; j<=K; j++) {
            cin >> t; in[t]++;
            adj[i].push_back(t);
            adj[t].push_back(i);
        }
    }
    memset(team, -1, sizeof(team)); team[R] = 0; dfs(R, 0, 0);
    vector<int> alive(2);
    for (int i=1; i<=N; i++) {
        if (!in[i]) {
            alive[team[i]]++;
        }
    }
    if (team[R]) cout << alive[1] << " " << alive[0];
    else cout << alive[0] << " " << alive[1];
}