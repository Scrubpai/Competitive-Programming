#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
#define ms(x, y) memset(x, y, sizeof(x))

const int MM = 3e5 + 5;
const int MX = 29;
int n, a[MM], ans, x = 1, trie[MM*30][2], cnt[MM*30][2], pre[MM]; long long inv;

void solve(int tc) {

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int j = MX; j >= 0; j--) {
        long long cnt0 = 0, cnt1 = 0;
        for (int i = 1; i <= n; i++) {
            int node = 0;
            if (a[i] & (1 << (j+1))) {
                if (!trie[pre[i]][1]) trie[pre[i]][1] = x, node = x++;
                else node = trie[pre[i]][1];
            } else {
                if (!trie[pre[i]][0]) trie[pre[i]][0] = x, node = x++;
                else node = trie[pre[i]][0];
            }
            pre[i] = node;
            if (a[i] & (1 << j)) {
                cnt1 += cnt[node][0];
                cnt[node][1]++;
            } else {
                cnt0 += cnt[node][1];
                cnt[node][0]++;
            }
        }
        if (cnt0 > cnt1) ans += (1 << j);
        inv += min(cnt0, cnt1);
    }
    cout << inv << " " << ans << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}