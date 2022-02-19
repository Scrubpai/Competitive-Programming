#include <bits/stdc++.h>
using namespace std;
const int MM = 2e3+5;
int N, T;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N >> T; queue<int> q[N+1]; vector<int> ans(N+1);
    for (int i=1, x; i<=N; i++) { cin >> x; q[i].push(x); }
    for (int i=1; i<=T; i++) {
        vector<int> nxt(N+1, -1);
        for (int j=1; j<=N; j++) {
            if (!q[j].empty()) {
                nxt[j] = q[j].front();
                ans[j] = nxt[j];
                q[j].pop();
            }
        }
        for (int j=1; j<=N; j++) {
            if (nxt[j] != -1) {
                q[nxt[j]].push(j);
            }
        }
    }
    cout << ans[1];
    for (int i=2; i<=N; i++) cout << ' ' << ans[i];
    cout << '\n';
}