#include <bits/stdc++.h>
using namespace std;
#define nl '\n'

const int MM = 1e5 + 5;
int n, a[MM], b[MM];

void solve(int tc) {

    cin >> n;
    for (int i = 1; i <= n; i++) { cin >> a[i]; b[i] = a[i]; }
    sort(b + 1, b + 1 + n);
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] != b[i]) cnt++;
    }
    if (cnt != 0 && cnt != 2) cout << "NO";
    else cout << "YES";

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}