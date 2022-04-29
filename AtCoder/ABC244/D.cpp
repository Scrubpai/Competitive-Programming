#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<char> s(3), t(3);
    int cnt = 0;
    cin >> s[0] >> s[1] >> s[2] >> t[0] >> t[1] >> t[2];
    for (int i=0; i<3; i++) cnt += (s[i] != t[i]);
    if (cnt==0 || cnt==3) cout << "Yes\n";
    else cout << "No\n";
}