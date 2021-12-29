#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        if (count(s.begin(), s.end(), 'N') == 1) cout << "NO" << '\n';
        else cout << "YES" << '\n';
    }
}