#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
int A, B, C, cnt[11];
void solve(int tc) {
    cin >> A >> B >> C;
    cnt[A]++; cnt[B]++; cnt[C]++;
    if (cnt[5] == 2 && cnt[7] == 1) cout << "YES" << nl;
    else cout << "NO" << nl;
}
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}