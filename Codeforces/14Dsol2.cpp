#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define nl '\n'

const int MM = 1e5 + 5;
int n, len[MM], outlen[MM], dpi[MM], dpo[MM]; vector<int> adj[MM];

//dfs in
// for every node what is the longest length path in it's sub tree
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

//dfs out
// for every node what is the longest length in original tree excluding it's subtree
void dfso(int u, int p) {
    //find max1, max2 of dpi of its children --> mx1i and mx2i
    //find top3 longest length chain from this node down in it's subtree --> len1, len2, len3
    int mx1i = 0, mx2i = 0, len1 = 0, len2 = 0, len3 = 0;
    for (int v : adj[u]) {
        if (v != p) {
            if (dpi[v] > mx1i) mx2i = mx1i, mx1i = dpi[v];
            else if (dpi[v] > mx2i) mx2i = dpi[v];

            if (len[v] > len1) len3 = len2, len2 = len1, len1 = len[v];
            else if (len[v] > len2) len3 = len2, len2 = len[v];
            else if (len[v] > len3) len3 = len[v];
        }
    }

    for (int v : adj[u]) {
        if (v == p) continue;
        int use1 = len1, use2 = len2;
        //find top 2 longest length path from subtrees of u, excluding subtree of v
        if (len1 == len[v]) use1 = len2, use2 = len3;
        else if (len2 == len[v]) use2 = len3;


        //the length of longest chain from it's parent's subtree excluding subtree v
        //outlen: for every node, what is the length of the longest path in the parent tree of v, excluding subtree rooted at v
        int use3 = outlen[u];

        //find overall max1 and max2
        int arr[] = {use1, use2, use3}; sort(arr, arr + 3);
        outlen[v] = arr[2] + 1;

        //max. length path in the parent of v's subtree, excluding the subtree of v is: an answer from one of the children, or
        //the sum of the 2 longest path from its subtrees excluding subtree of v
        //use0: longest path from one of the subtrees of u, excluding subtree of v
      //  if (use0 > use1 + use2 + 1) cout << u << " " << v << nl;
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
    dfsi(1, 0);
    dfso(1, 0);
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