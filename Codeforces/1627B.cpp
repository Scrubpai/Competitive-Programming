#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
#define f first
#define s second
const int MM = 1e5+5;
int dir[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m; vector<vector<int>> ans(n, vector<int>(m, -1)); queue<pi> q;
        vector<int> out;
        if (n%2==1) {
            q.push({n/2, m/2}); ans[n/2][m/2] = n/2+m/2;
            if (m%2==0) q.push({n/2, m/2-1}), ans[n/2][m/2-1] = n/2+m/2;
        } else {
            q.push({n/2, m/2}); q.push({n/2-1, m/2}); ans[n/2][m/2] = ans[n/2-1][m/2] = n/2+m/2;
            if (m%2==0) q.push({n/2, m/2-1}), ans[n/2][m/2-1] = n/2+m/2, q.push({n/2-1, m/2-1}), ans[n/2-1][m/2-1] = n/2+m/2;
        }
        while (!q.empty()) {
            pi cur = q.front(); q.pop(); out.push_back({ans[cur.f][cur.s]});
            for (int k=0; k<4; k++) {
                int nr = cur.f + dir[k][0], nc = cur.s + dir[k][1];
                if (nr>=0 && nr<n && nc>=0 && nc<m && ans[nr][nc]==-1) {
                    ans[nr][nc] = ans[cur.f][cur.s] + 1;
                    q.push({nr, nc});
                }
            }
        }
        sort(out.begin(), out.end());
        for (int x : out) cout << x << " ";
        cout << "\n";
    }
}