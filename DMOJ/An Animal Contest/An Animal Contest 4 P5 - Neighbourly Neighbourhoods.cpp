#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
const int MM = 5e5+5;
int N, M, X, Q, dsu[MM], idx=1; vector<int> scc1[MM], scc2[MM];
int fd(int x) { if (dsu[x] == x) return x; else return dsu[x] = fd(dsu[x]); }
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N >> M >> X >> Q;
    for (int i=1; i<=N; i++) dsu[i] = i;
    for (int i=1, x, y; i<=Q; i++) {
        cin >> x >> y;
        int fx = fd(x), fy = fd(y);
        if (fx != fy) dsu[fx] = fy;
    }
    for (int i=1; i<=N; i++) scc1[fd(i)].push_back(i);
    int P = 0; vector<pi> sz;
    for (int i=1; i<=N; i++) {
        if ((int)scc1[i].size()) {
            P++;
            sz.push_back({(int)scc1[i].size(), i});
        }
    }
    if (P < X) { cout << -1 << '\n'; return 0; }
    sort(sz.begin(), sz.end(), greater<pi>());
    for (int i=0; i<P-X+1; i++) {
        for (int u : scc1[sz[i].second]) {
            scc2[idx].push_back(u);
        }
    }
    for (int i=P-X+1; i<(int)sz.size(); i++) {
        idx++;
        for (int u : scc1[sz[i].second]) {
            scc2[idx].push_back(u);
        }
    }
    int tot = 0; vector<pi> ans;
    for (int i=1; i<=idx; i++) {
        if ((int)scc2[i].size() > 1) {
            tot += (int)scc2[i].size(); ans.push_back({scc2[i][(int)scc2[i].size()-1], scc2[i][0]});
            for (int j=1; j<(int)scc2[i].size(); j++) ans.push_back({scc2[i][j-1], scc2[i][j]});
        }
    }
    if (tot > M) { cout << -1 << '\n'; return 0; }
    for (int i=1; i<=idx && tot<M; i++) {
        int n = (int)scc2[i].size();
        if (n > 1) {
            for (int j=0; j<n && tot<M; j++) {
                for (int k=0; k<n && tot<M; k++) {
                    int u = scc2[i][j], v = scc2[i][k];
                    if (k == j+1 || (j==n-1 && k==0) || k==j) continue;
                    tot++; ans.push_back({u, v});
                }
            }
        }
    }
    for (int i=1; i<=idx && tot<M; i++) {
        for (int j=i+1; j<=idx && tot<M; j++) {
            for (int u : scc2[i]) {
                if (tot == M) break;
                for (int v : scc2[j]) {
                    if (tot == M) break;
                    tot++; ans.push_back({u, v});
                }
            }
        }
    }
    if (tot < M) { cout << -1 << '\n'; return 0; }
    for (pi p : ans) cout << p.first << " " << p.second << '\n';
}