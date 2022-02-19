#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int N, M, K; cin >> N >> M >> K; vector<int> ans(N+1, -1), val(N+1);
    for (int i=1, A, B, C; i<=K; i++) {
        cin >> A >> B >> C;
        if (ans[B] == -1) ans[B] = A, val[B] = C;
        else if (C > val[B]) val[B] = C, ans[B] = A;
    }
    cout << ans[1];
    for (int i=2; i<=N; i++) cout << ' ' << ans[i];
}