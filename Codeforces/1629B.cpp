#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int l, r, k; cin >> l >> r >> k;
        if (l==r) {
            if (l>1) cout << "YES\n";
            else cout << "NO\n";
        } else {
            if (k < (r+1)/2 - l/2) cout << "NO\n";
            else cout << "YES\n";
        }
    }
}