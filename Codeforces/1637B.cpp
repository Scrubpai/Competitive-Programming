#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n; vector<int> a(n);
        for (int i=0; i<n; i++) cin >> a[i];
        int ans = 0;
        for (int i=0; i<n; i++) {
            for (int j=i; j<n; j++) {
                ans += j-i+1;
                for (int k=i; k<=j; k++) {
                    if (!a[k]) ans++;
                }
            }
        }
        cout << ans << '\n';
    }
}