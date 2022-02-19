#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
const int MM = 2e5+5, base1 = 131, base2 = 137, mod = 1e9+7;
string s, t[MM]; vector<int> adj[MM]; int n, k[MM], ans[MM], Q; ll hsh1[MM], hsh2[MM], p1[MM], p2[MM]; map<ll, vector<int>> mp;
void init() {
    p1[0] = p2[0] = 1;
    for (int i=1; i<=n; i++) {
        hsh1[i] = (hsh1[i-1] * base1 + s[i-1]) % mod;
        p1[i] = (p1[i-1] * base1) % mod;
        hsh2[i] = (hsh2[i-1] * base2 + s[i-1]) % mod;
        p2[i] = (p2[i-1] * base2) % mod;
    }
}
ll getHash(string &x) {
    ll h1 = 0, h2 = 0;
    for (int i=1; i<=x.length(); i++) {
        h1 = (h1 * base1 + x[i-1]) % mod;
        h2 = (h2 * base2 + x[i-1]) % mod;
    }
    return (h1 << 31) | h2;
}
ll sub(int l, int r) {
    ll v1 = (hsh1[r] - hsh1[l-1] * p1[r-l+1] % mod + mod) % mod;
    ll v2 = (hsh2[r] - hsh2[l-1] * p2[r-l+1] % mod + mod) % mod;
    return (v1 << 31)| v2;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> s; n = s.length(); init();
    cin >> Q; set<int> st;
    for (int i=0; i<Q; i++) {
        cin >> t[i] >> k[i];
        st.insert(t[i].length());
        adj[t[i].length()].push_back(i);
    }
    for (int x : st) {
        mp.clear();
        for (int i=x; i<=n; i++) {
            mp[sub(i-x+1, i)].push_back(i-x+1);
        }
        for (int i=0; i<(int)adj[x].size(); i++) {
            ll curHash = getHash(t[adj[x][i]]);
            if (k[adj[x][i]] > mp[curHash].size()) ans[adj[x][i]] = -1;
            else ans[adj[x][i]] = mp[curHash][k[adj[x][i]]-1];
        }
    }
    for (int i=0; i<Q; i++) cout << ans[i] << '\n';
}