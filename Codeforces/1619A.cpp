#include <bits/stdc++.h>
using namespace std;
int T; string s;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> T;
    while (T--) {
        cin >> s;
        int l = s.size();
        if (l % 2 == 1) { printf("NO\n"); continue; }
        if (s.substr(0, l/2) == s.substr(l/2, l/2)) printf("YES\n");
        else printf("NO\n");
    }
}