#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
int a[3]; string s;
void solve(int tc) {
    cin >> a[0] >> a[1] >> a[2];
    sort(a, a + 3);
    cin >> s;
    for (int i = 0; i < 3; i++) {
        if (s[i] == 'A') cout << a[0] << ' ';
        else if (s[i] == 'B') cout << a[1] << ' ';
        else cout << a[2] << ' ';
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}