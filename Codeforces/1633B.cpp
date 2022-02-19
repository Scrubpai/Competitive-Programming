#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        int n = (int)s.size(), cnt0 = 0, cnt1 = 0;
        if (n <= 2) { cout << 0 << '\n'; continue; }
        for (int i=0; i<n; i++) {
            if (s[i]=='0') cnt0++;
            else cnt1++;
        }
        if (cnt0 == cnt1) {
            cout << cnt0-1 << '\n';
        } else {
            cout << min(cnt0, cnt1) << '\n';
        }
    }
}