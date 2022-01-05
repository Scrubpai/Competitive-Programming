#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
typedef pair<int, int> pii;

const int MM = 1e5 + 5;
int n, m, x = 1, trie[MM][26], l, r, trie2[MM][26], ans[MM], rt[MM]; string s, a[MM]; vector<int> LEAF[MM], val[MM]; pii queries[MM];

void solve(int tc) {

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> s; a[i] = s;
        int node = 0;
        for (int j = 0; j < s.size(); j++) {
            if (!trie[node][s[j]-'a']) {
                trie[node][s[j]-'a'] = x;
                node = x++;
            } else node = trie[node][s[j]-'a'];
        }
        LEAF[node].push_back(i);
    }
    x = 1;
    for (int i = 1; i <= m; i++) {
        cin >> s >> l >> r;
        queries[i] = {l, r};
        int node = 0;
        for (int j = 0; j < s.size(); j++) {
            if (!trie2[node][s[j]-'a']) {
                trie2[node][s[j]-'a'] = x;
                node = x++;
            } else node = trie2[node][s[j]-'a'];
        }
        rt[i] = node;
        node = 0;
        for (int j = 0; j < s.size(); j++) {
            if (!trie[node][s[j] - 'a']) break;
            else node = trie[node][s[j] - 'a'];
            int lo = lower_bound(LEAF[node].begin(), LEAF[node].end(), l) - LEAF[node].begin();
            int hi = upper_bound(LEAF[node].begin(), LEAF[node].end(), r) - LEAF[node].begin();
            ans[i] += hi - lo;
        }
    }
    for (int i = 1; i <= n; i++) {
        int node = 0;
        for (int j = 0; j < a[i].size() - 1; j++) {
            if (!trie2[node][a[i][j]-'a']) break;
            node = trie2[node][a[i][j]-'a'];
            val[node].push_back(i);
        }
    }
    for (int i = 1; i <= m; i++) {
        int lo = lower_bound(val[rt[i]].begin(), val[rt[i]].end(), queries[i].first) - val[rt[i]].begin();
        int hi = upper_bound(val[rt[i]].begin(), val[rt[i]].end(), queries[i].second) - val[rt[i]].begin();
        cout << ans[i] + hi - lo << nl;
    }

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}