#include <bits/stdc++.h>
using namespace std;
#define nl '\n'

int n, freq[2005];

void solve(int tc) {

    cin >> n;
    for (int i = 1, l; i <= n; i++) {
        cin >> l; freq[l]++;
    }
    int cnt = 0, ans = 0;
    for (int sum = 4000; sum >= 2; sum--) {
        int num = 0;
        for (int i = 1; i <= sum/2; i++) {
            if (sum - i > 2000) continue;
            if (i != sum - i) num += min(freq[i], freq[sum - i]);
            else num += (freq[i] / 2);
        }
        if (num > ans) { cnt = 1; ans = num; }
        else if (num == ans) cnt++;
    }
    cout << ans << " " << cnt << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}