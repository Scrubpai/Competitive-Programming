#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5 + 5;
#define nl '\n'
int n, m, a[MM], st[MM], t[MM], r[MM], top, tmp[MM];
void solve(int tc) {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) { cin >> a[i]; tmp[i] = a[i]; }
    for (int i = 1; i <= m; i++) {
        cin >> t[i] >> r[i];
        while (top > 0 && r[i] >= r[st[top]]) top--;
        st[++top] = i;
    }
    st[++top] = 0; r[0] = 0;
    sort(tmp + 1, tmp + 1 + r[st[1]]);
    int lft = 1, rit = r[st[1]];
    for (int i = 2; i <= top; i++) {
        for (int j = r[st[i-1]]; j > r[st[i]]; j--) {
            if (t[st[i-1]] == 1) a[j] = tmp[rit--];
            else a[j] = tmp[lft++];
        }
    }
    for (int i = 1; i <= n; i++) cout << a[i] << ' ';
}
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}