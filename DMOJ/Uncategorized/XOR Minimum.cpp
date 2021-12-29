#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
typedef long long ll;

const int MM = 2e6 + 5;
int n, q, trie[MM][2], a[MM], v; unordered_map<int, int> idx;

void solve(int tc) {

    cin >> n >> q;
    int x = 1, cur = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (idx[a[i]] == 0 && a[0] != a[i]) idx[a[i]] = i;
        int node = 0;
        for (int j = 29; j >= 0; j--) {
            if (a[i] & (1 << j)) {
                if (trie[node][1]) node = trie[node][1];
                else trie[node][1] = x, node = x++;
            } else {
                if (trie[node][0]) node = trie[node][0];
                else trie[node][0] = x, node = x++;
            }
        }
    }
    while (q--) {
        cin >> v;
        cur ^= v;
        int node = 0, ans = 0;
        for (int i = 29; i >= 0; i--) {
            if (cur & (1 << i)) {
                if (trie[node][1]) node = trie[node][1];
                else node = trie[node][0], ans += (1 << i);
            } else {
                if (trie[node][0]) node = trie[node][0];
                else if (trie[node][1]) node = trie[node][1], ans += (1 << i);
            }
        }
        int val = 0;
        for (int i = 29; i >= 0; i--) {
            if (ans & (1 << i)) {
                if (!(cur & (1 << i))) val += (1 << i);
            } else {
                if (cur & (1 << i)) val += (1 << i);
            }
        }
        cout << idx[val] << nl;
    }

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}