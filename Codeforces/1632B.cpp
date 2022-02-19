#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n; n--;
        int x = 31 - __builtin_clz(n);
        for (int i=(1<<x); i<=n; i++) cout << i << " ";
        cout << (n^(1<<x)) << " ";
        for (int i=0; i<(1<<x); i++) if (i!=(n^(1<<x))) cout << i << " ";
        cout << '\n';
    }
}