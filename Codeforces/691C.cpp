#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
string s;
void solve(int tc) {
    cin >> s;
    bool flag = 0;
    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] == '.') { flag = 1; break; }
    }
    if (!flag) s += '.';
    int i = 0;
    for (; i < (int)s.size(); i++) {
        if (s[i] != '0') break;
    }
    s = s.substr(i, (int)s.size() - i + 1);
    i = (int)s.size() - 1;
    for (; i >= 0; i--) {
        if (s[i] != '0') break;
    }
    s = s.substr(0, i + 1);
    int lastpos = 0, decimal = (int)s.size(), firstpos = (int)s.size();
    for (int j = 0; j < (int)s.size(); j++) {
        if (s[j] == '.') decimal = j;
        if (s[j] >= '1' && s[j] <= '9') firstpos = min(firstpos, j), lastpos = max(lastpos, j);
    }
    if (decimal - firstpos - 1 == 0) {
        for (int j = firstpos; j <= lastpos; j++) cout << s[j];
    } else {
        int cnt = decimal - firstpos - 1;
        if (decimal < firstpos) cnt++;
        for (int j = firstpos; j <= lastpos; j++) {
            if (s[j] == '.') continue;
            cout << s[j];
            if (j == firstpos && j != lastpos) cout << '.';
        }
        cout << 'E';
        cout << cnt;
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}