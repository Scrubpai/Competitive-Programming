#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+5;
int n; char s[MM];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        cin >> n;
        for (int i=0; i<n; i++) cin >> s[i];
        for (int i=1; i<=n; i++) {
            if (i==n || s[i] > s[i-1] || (s[i] == s[i-1] && s[0] == s[i])) {
                for (int j=0; j<i; j++) cout << s[j];
                for (int j=i-1; j>=0; j--) cout << s[j];
                goto next;
            }
        }
        next: cout << '\n';
    }
}