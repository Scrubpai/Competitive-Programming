#include <bits/stdc++.h>
using namespace std;
#define nl '\n'

const int MM = 5e5 + 5;
int n, trie[MM][26], x = 1, m, mx, marked[MM]; string s; char mp[MM];

void dfs(int cur) {
    if (marked[cur] > 1) cout << "P" << nl;
    int nxt = -1;
    for (int k = 0; k < 26; k++) {
        int v = trie[cur][k];
        if (!v) continue;
        if (marked[v] == 1 || marked[v] == 3) { nxt = v; continue; }
        cout << mp[v] << nl;
        dfs(v);
        cout << "-" << nl;
    }
    if (nxt != -1) {
        cout << mp[nxt] << nl;
        dfs(nxt);
    }
}

void solve(int tc) {

    cin >> n;
    for (int t = 0; t < n; t++) {
        string str; cin >> str;
        int node = 0;
        for (int i = 0; i < str.size(); i++) {
            if (!trie[node][str[i]-'a']) {
                trie[node][str[i]-'a'] = x; m += 2;
                mp[x] = str[i];
                node = x++;
            } else {
                node = trie[node][str[i]-'a'];
            }
        }
        marked[node] += 2; //leaf node
        if (mx < str.size()) mx = str.size(), s = str;
    }
    int node = 0;
    for (int i = 0; i < s.size(); i++) {
        node = trie[node][s[i]-'a']; marked[node]++;
        //mark that this is the last word to create
    }
    cout << m + n - mx << nl;
    dfs(0);

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}