#include <bits/stdc++.h>
using namespace std;
const int MM = 2005;
int N, M, S, F, L, R, k[MM], ans[MM][MM];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N >> M >> S >> F >> L >> R;
    int last = -1, cnt = 0;
    for (int i=1; i<=M; i++) {
        cin >> k[i];
        if (k[i] == F) last = i;
    }
    if ((last == -1 || R == 0) && S != F) { cout << -1 << '\n'; return 0; }
    int cur = S;
    for (int i=max(last-R+1, 1); i<=last; i++) {
        ans[cur][i] = 1;
        cnt++; cur = k[i];
    }
    for (int i=1; i<=N; i++) {
        if (cnt >= L && cnt <= R) break;
        for (int j=1; j<=M; j++) {
            if (i == F && j>last) break;
            if (cnt >= L && cnt <= R) break;
            if (ans[i][j] != 1) {
                ans[i][j] = 1;
                cnt++;
            }
        }
    }
    if (cnt < L || cnt > R) { cout << -1 << '\n'; return 0; }
    cout << cnt << '\n';
    for (int i=1; i<=N; i++) {
        for (int j=1; j<M; j++) {
            cout << ans[i][j] << ' ';
        }
        cout << ans[i][M] << '\n';
    }
}