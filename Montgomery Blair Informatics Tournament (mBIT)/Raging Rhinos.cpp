#include <bits/stdc++.h>
using namespace std;
#define nl '\n'

const int MM = 1e5 + 5;
int n, s[MM], d[MM], m; stack<int> st; bool ded[MM];

void solve(int tc) {

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s[i] >> d[i];
        if (d[i] == 1) st.push(i);
        else if (d[i] == 0) {
            while (!st.empty()) {
                int j = st.top();
                if (s[i] > s[j]) { ded[j] = 1; st.pop(); s[i] -= s[j]; }
                else if (s[i] == s[j]) { ded[i] = 1; ded[j] = 1; st.pop(); break; }
                else if (s[i] < s[j]) { s[j] -= s[i]; ded[i] = 1; break; }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (!ded[i]) m++;
    }
    cout << m << nl;
    for (int i = 1; i <= n; i++) {
        if (!ded[i]) cout << s[i] << " " << d[i] << nl;
    }

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}