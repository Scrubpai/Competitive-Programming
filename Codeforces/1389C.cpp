#include <bits/stdc++.h>
using namespace std;
#define nl '\n'

const int MM = 2e5 + 5;
string s; int a[MM];

void solve(int tc) {

    cin >> s;
    int n = s.size();
    for (int i = 0; i < n; i++) a[i+1] = s[i]-'0';
    int ans = 0;
    for (int x = 0; x < 10; x++) {
        for (int y = 0; y < 10; y++) {
            int cnt = 0, len = 0;
            for (int i = 1; i <= n; i++) {
                if (a[i] == x && cnt % 2 == 0) {
                    cnt++; len++;
                } else if (a[i] == y && cnt % 2 == 1) {
                    cnt++; len++;
                }
            }
            if (cnt % 2 == 1 && x != y) len--;
            ans = max(ans, len);
        }
    }
    cout << min(n - ans, n - 2) << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int tc = 1; cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}