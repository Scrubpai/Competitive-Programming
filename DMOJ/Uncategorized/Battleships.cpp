#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define nl '\n'
#define ms(x, y) memset(x, y, sizeof(x))

int m, n, s, cnt; char ch; ll sum; bool a[2005][2005];

void solve(int tc) {

    cin >> m >> n >> s;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> ch;
            a[i][j] = (ch == 'X');
            int r1 = max(1, i - s + 1), r2 = min(m, i + s - 1), c1 = max(1, j - s + 1), c2 = min(n, j + s - 1);
            int len = r2 - r1 + 1 - s + 1, wid = c2 - c1 + 1 - s + 1;
            sum += 1LL * len * wid * a[i][j];
            if (i >= s && j >= s) cnt++;
        }
    }
    double ans = (1.0 * sum) / cnt;
    printf("%.8f\n", ans);

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}