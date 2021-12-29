#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+5;
int N, last[MM], tmp[MM]; string a[MM], ans;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N;
    for (int i=1; i<=N; i++) cin >> a[i];
    for (char c='z'; c>='a'; ) {
        bool flag = 1;
        for (int i=1; i<=N; i++) {
            tmp[i] = a[i].find(c, last[i]);
            if (tmp[i] == -1) { flag = 0; break; }
        }
        if (!flag) { c--; continue; }
        ans += c;
        for (int i=1; i<=N; i++) last[i] = tmp[i] + 1;
    }
    if (ans.empty()) cout << -1 << '\n';
    else cout << ans << '\n';
}