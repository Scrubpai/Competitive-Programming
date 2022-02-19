#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n; string s; cin >> n >> s;
        if (n == 1 || (n == 2 && s[0] != s[1])) cout << "YES\n";
        else cout << "NO\n";
    }
}