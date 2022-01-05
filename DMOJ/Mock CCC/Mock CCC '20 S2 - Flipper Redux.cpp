#include <bits/stdc++.h>
using namespace std;
const int MM = 2e3+5;
#define nl '\n'
struct flip { char c; int val; };
int N, a[MM][MM]; vector<flip> res;
int main() {
    cin >> N;
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            cin >> a[i][j];
        }
        if (i>=2) {
            if (a[i][1] != a[i-1][1]) {
                for (int j=1; j<=N; j++) a[i][j] = !a[i][j];
                res.push_back({'R', i});
            }
        }
    }
    for (int j=1; j<=N; j++) {
        if (a[1][j]) {
            res.push_back({'C', j});
            for (int i=1; i<=N; i++) {
                a[i][j] = !a[i][j];
                if (a[i][j]) { cout << -1 << nl; return 0; }
            }
        }
        for (int i=1; i<=N; i++) {
            if (a[i][j]) { cout << -1 << nl; return 0; }
        }
    }
    cout << res.size() << nl;
    for (flip f : res) cout << f.c << " " << f.val << nl;
    return 0;
}