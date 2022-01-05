#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
#define ms(x, y) memset(x, y, sizeof(x))

const int MM = 1e6 + 5;
int n, trie[MM][30]; string s;

void solve(int tc) {

    cin >> n; ms(trie, 0);
    int ans = 0, x = 1;
    while (n--) {
        cin >> s;
        int node = 0; bool flag = 0;
        for (int i = 0; i < s.size(); i++) {
            if (trie[node][s[i]-'a']) {
                node = trie[node][s[i]-'a'];
            } else {
                if (!flag) ans += i + 1, flag = 1;
                trie[node][s[i]-'a'] = x;
                node = x++;
            }
        }
        if (!flag) ans += s.size();
    }
    printf("Case #%d: %d\n", tc, ans);

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int tc = 1; cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}