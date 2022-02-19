#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    string s, t; cin >> s; t.push_back(s[0]);
    for (int i=1; i<(int)s.length(); i++) {
        if ((s[i] == 'A' && s[i-1] != 'A') || (s[i] != 'A' && s[i-1] == 'A')) t.push_back(s[i]);
        else { cout << t << " "; t = ""; t.push_back(s[i]); }
    }
    cout << t << '\n';
}