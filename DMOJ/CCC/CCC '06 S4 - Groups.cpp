#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
int n, arr[105][105];
void solve(int tc) {
    while (1) {
        cin >> n;
        if (!n) break;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> arr[i][j];
            }
        }
        bool flag = 0;
        int identity = 0;
        for (int i = 1; i <= n; i++) {
            flag = 1;
            for (int j = 1; j <= n; j++) {
                if (arr[i][j] != j) { flag = 0; break; }
            }
            if (flag) { identity = i; break; }
        }
        if (!flag) { cout << "no" << nl; continue; }
        for (int i = 1; i <= n; i++) {
            int cnt = 0;
            for (int j = 1; j <= n; j++) {
                if (arr[i][j] == identity) cnt++;
            }
            if (cnt == 0) { flag = 0; break; }
        }
        if (!flag) { cout << "no" << nl; continue; }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                for (int k = 1; k <= n; k++) {
                    if (arr[i][arr[j][k]] != arr[arr[i][j]][k]) {
                        flag = 0;
                        goto stop;
                    }
                }
            }
        }
        stop:
        if (!flag) cout << "no" << nl;
        else cout << "yes" << nl;
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}