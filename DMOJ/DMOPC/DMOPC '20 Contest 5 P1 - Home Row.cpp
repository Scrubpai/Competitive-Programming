#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    string s, t; cin >> s >> t;
    int n = (int)s.size(), m = (int)t.size();
    for (int i=0; i<min(n, m); i++)
        if (s[i] != t[i]) { cout << m+n-2*i << '\n'; return 0; }
    cout << max(n, m) - min(n, m) << '\n';
}