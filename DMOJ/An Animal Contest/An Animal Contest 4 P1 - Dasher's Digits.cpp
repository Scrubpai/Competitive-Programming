#include <bits/stdc++.h>
using namespace std;
const int MM = 1e6+5;
int n, m, a[MM]; string s;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> m >> s;
    int mx = 0;
    for (int i=0; i<m; i++) {
        cin >> a[i];
        mx = max(mx, a[i]);
    }
    bool flag = 0;
    string pre = "", suf = "";
    for (int i=n-1; i>=0; i--) {
        if (s[i]=='0') {
            if (a[--m] == mx) {
                if (!flag) flag = 1;
            }
        } else {
            if (!flag) suf += s[i];
            else pre += s[i];
        }
    }
    reverse(pre.begin(), pre.end()); reverse(suf.begin(), suf.end());
    cout << suf << pre << '\n';
}