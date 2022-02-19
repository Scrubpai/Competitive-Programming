#include <bits/stdc++.h>
using namespace std;
int n, t, ans, a[15];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> t;
    for (int i=0; i<n; i++) cin >> a[i];
    for (int i=0; i<(1<<n); i++) {
        int sum = 0;
        for (int j=0; j<n; j++) {
            if (i&(1<<j)) sum += a[j];
        }
        ans += sum==t;
    }
    cout << ans << '\n';
}