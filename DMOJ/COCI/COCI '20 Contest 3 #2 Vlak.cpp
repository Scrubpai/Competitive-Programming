#include <bits/stdc++.h>
using namespace std;
const int MM = 2e6+5;
#define nl '\n'
int n, m, x; string str;
struct node {
    int mask;
    node* child[26];
    node() {
        mask = 0;
        for (int i=0; i<26; i++) child[i]=NULL;
    }
} nodes[MM];
node* newNode() { return &nodes[x++]; }
struct Trie {
    node* root;
    Trie() { root = newNode(); }
    //0 = nina, 1 = emilija
    void insert(node* cur, const string &s, int pos, int dp) {
        if (pos == (int)s.size()) return;
        if (!cur->child[s[pos]-'a']) cur->child[s[pos]-'a'] = newNode();
        cur->child[s[pos]-'a']->mask |= dp;
        insert(cur->child[s[pos]-'a'], s, pos+1, dp);
    }
    //return 0 if lose, return 1 if win, turn = 0 is nina, turn = 1 is emilija
    int fun(node* cur, int turn) {
        for (int i=0; i<26; i++) {
            if (cur->child[i] && (cur->child[i]->mask & (1<<turn)) && !fun(cur->child[i], turn^1)) return 1;
        }
        return 0;
    }
} T;
void solve(int tc) {
    cin >> n;
    for (int i=0; i<n; i++) { cin >> str; T.insert(T.root, str, 0, (1<<0)); }
    cin >> m;
    for (int i=0; i<m; i++) { cin >> str; T.insert(T.root, str, 0, (1<<1)); }
    if (T.fun(T.root, 0)) cout << "Nina" << nl;
    else cout << "Emilija" << nl;
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); int tc = 1; /*cin >> tc;*/ for (int t = 1; t <= tc; t++) solve(t); return 0; }