#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
int N;
bool check(int x) {
    while (x) { if (x % 10 == 7) return 0; x /= 10; }
    return 1;
}
bool check2(int x) {
    while (x) { if (x % 8 == 7) return 0; x /= 8; }
    return 1;
}
void solve(int tc) {
    cin >> N;
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        if (check(i) && check2(i)) ans++;
    }
    cout << ans << nl;
}
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}