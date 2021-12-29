#include <bits/stdc++.h>
using namespace std;
#define nl '\n'

const int MM = 2e5 + 5;
int n, a[MM]; string s;

void solve(int tc) {

    cin >> n >> s; s = " " + s;
    int ans = 0;
    for (int i = 1; i <= n; i++) a[i] = s[i] - '0';
    int i = 1, j = 1;
    for (; i <= n; i++) {
        if (j < i) j = i;
        bool flag = 0;
        for (; j < n; j++) {
            if (a[j+1] == a[j]) { flag = 1; break; }
        }
        if (!flag) break;
        j++;
        ans++;
        while (i <= n && a[i+1] == a[i]) i++;
    }
    if (i > n) { cout << ans << nl; return; }
    int cnt = 1;
    for (; i < n; i++) {
        if (a[i+1] != a[i]) cnt++;
    }
    ans += (cnt + 1) / 2;
    cout << ans << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int tc = 1; cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}