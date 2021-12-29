#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define nl '\n'

//dpi[i]: length of the longest path in node i's subtree
//dpo[i]: length of the longest path that passes through the parent of i in the original tree, if i remove node i and its subtree

const int MM = 1e5 + 5;
int n, len[MM], outlen[MM], dpi[MM], dpo[MM]; vector<int> adj[MM];

void dfsi(int u, int p) {
    int mx1 = 0, mx2 = 0, val = 0;
    for (int v : adj[u]) {
        if (v != p) {
            dfsi(v, u);
            if (len[v] > mx1) mx2 = mx1, mx1 = len[v];
            else if (len[v] > mx2) mx2 = len[v];
            val = max(val, dpi[v]);
        }
    }
    len[u] = mx1 + 1;
    dpi[u] = max(mx1 + mx2 + 1, val);
}

void dfso(int u, int p) {
    int len1 = 0, len2 = 0, len3 = 0;
    for (int v : adj[u]) {
        if (v != p) {
            if (len[v] > len1) len3 = len2, len2 = len1, len1 = len[v];
            else if (len[v] > len2) len3 = len2, len2 = len[v];
            else if (len[v] > len3) len3 = len[v];
        }
    }

    for (int v : adj[u]) {
        if (v == p) continue;
        int use1 = len1, use2 = len2, use3 = outlen[u];
        if (len1 == len[v]) use1 = len2, use2 = len3;
        else if (len2 == len[v]) use2 = len3;
        
        int arr[] = {use1, use2, use3}; sort(arr, arr + 3);
        outlen[v] = arr[2] + 1;
        
        dpo[v] = arr[1] + arr[2] + 1;
        dfso(v, u);
    }
}

void solve(int tc) {

    cin >> n;
    for (int i = 1, x, y; i < n; i++) {
        cin >> x >> y;
        adj[x].push_back(y); adj[y].push_back(x);
    }
    dfsi(1, 0); dfso(1, 0);
    ll ans = 0;
    for (int i = 1; i <= n; i++) ans = max(ans, 1ll*(dpi[i]-1)*(dpo[i]-1));
    cout << ans << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}