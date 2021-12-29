#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+5;
typedef long long ll;
int N, M; ll dp1[MM], dp2[MM]; vector<int> adj[MM], c[MM]; vector<ll> tmp[MM], pre[MM], suf[MM];
void dfs1(int u, int pa) {
    dp1[u] = 1;
    for (int v : adj[u]) {
        if (v == pa) continue;
        dfs1(v, u); dp1[u]=(dp1[u]*dp1[v])%M; tmp[u].push_back(dp1[v]); c[u].push_back(v);
    }
    dp1[u]++;
}
void dfs2(int u, int pa) {
    ll lst = 1; pre[u].push_back(lst);
    for (int i=0; i<(int)tmp[u].size(); i++) {
        lst = (lst*tmp[u][i])%M;
        pre[u].push_back(lst);
    }
    lst = 1; suf[u].push_back(lst);
    for (int i=(int)tmp[u].size()-1; i>=0; i--) {
        lst = (lst*tmp[u][i])%M;
        suf[u].push_back(lst);
    }
    reverse(suf[u].begin(), suf[u].end());
    for (int i=0; i<(int)c[u].size(); i++) {
        int v = c[u][i];
        if (v == pa) continue;
        dp2[v] = dp2[u]*pre[u][i]%M*suf[u][i+1]%M+1;
        dfs2(v, u);
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N >> M;
    for (int i=1, x, y; i<N; i++) {
        cin >> x >> y;
        adj[x].push_back(y); adj[y].push_back(x);
    }
    dfs1(1, 0); dp2[1] = 1; dfs2(1, 0);
    for (int i=1; i<=N; i++) cout << (dp1[i]-1+M)%M*dp2[i]%M << '\n';
}