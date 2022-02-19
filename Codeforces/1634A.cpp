#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k; string s; cin >> s;
        string tmp = s; reverse(tmp.begin(), tmp.end());
        if (!k) cout << 1 << '\n';
        else {
            if (s + tmp == tmp + s) cout << 1 << '\n';
            else cout << 2 << '\n';
        }
    }
}