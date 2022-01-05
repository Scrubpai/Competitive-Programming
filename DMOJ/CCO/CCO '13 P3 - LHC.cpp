#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 4e5+5;
int N, len[MM], dia; ll cnt[MM], num; vector<int> adj[MM];
void dfs(int u, int pa) {
    len[u] = 0; cnt[u] = 1;
    for (int v : adj[u]) {
        if (v == pa) continue;
        dfs(v, u);
        if (len[v] + len[u] + 1 > dia) {
            dia = len[v] + len[u] + 1;
            num = cnt[u] * cnt[v];
        } else if (len[v] + len[u] + 1 == dia) {
            num += cnt[u] * cnt[v];
        }
        if (len[v] + 1 > len[u]) len[u] = len[v] + 1, cnt[u] = cnt[v];
        else if (len[v] + 1 == len[u]) cnt[u] += cnt[v];
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N;
    for (int i=1, u, v; i<N; i++) {
        cin >> u >> v;
        adj[u].push_back(v); adj[v].push_back(u);
    }
    dfs(1, 0);
    printf("%d %lld\n", dia+1, num);
}