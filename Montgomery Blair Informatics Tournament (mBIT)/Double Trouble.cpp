#include <bits/stdc++.h>
using namespace std;
#define nl '\n'

const int MM = 1e4 + 5;
string s; bool vis[MM];

void solve(int tc) {

    getline(cin, s);
    int n = s.size();
    for (int i = 0; i < n - 1;) {
        int j = i;
        for (; j < n; j++) {
            if (s[j] != s[i]) break;
        }
        if (j - i == 2) vis[i] = 1;
        i = j;
    }
    for (int i = 0; i < n; i++) {
        if (vis[i]) continue;
        cout << s[i];
    }

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}