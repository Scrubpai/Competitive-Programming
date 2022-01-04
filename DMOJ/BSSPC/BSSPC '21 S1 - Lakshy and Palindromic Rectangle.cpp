#include <bits/stdc++.h>
using namespace std;
const int MM = 2005;
int N, M; char g[MM][MM];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N >> M;
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=M; j++) {
            cin >> g[i][j];
        }
    }
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=M/2; j++) {
            char a = g[i][j], b = g[i][M-j+1];
            if (a == '.' || b =='.') {
                if (a == '.') g[i][j] = g[i][M-j+1];
                else g[i][M-j+1] = g[i][j];
            } else if (a != b) { cout << -1 << '\n'; return 0; }
        }
    }
    for (int j=1; j<=M; j++) {
        for (int i=1; i<=N/2; i++) {
            char a = g[i][j], b = g[N-i+1][j];
            if (a == '.' || b =='.') {
                if (a == '.') g[i][j] = g[N-i+1][j];
                else g[N-i+1][j] = g[i][j];
            } else if (a != b) { cout << -1 << '\n'; return 0; }
        }
    }
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=M; j++) {
            if (g[i][j] == '.') cout << "a";
            else cout << g[i][j];
        }
        cout << '\n';
    }
}