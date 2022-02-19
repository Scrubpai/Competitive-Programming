#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n), suf(n+1), vis(n+1);
        for (int i=0; i<n; i++) cin >> a[i];
        for (int i=n-1, j=0; i>=0; i--) {
            vis[a[i]] = 1;
            while (vis[j]) j++;
            suf[i] = j;
        }
        vector<int> ans; fill(vis.begin(), vis.end(), 0);
        for (int i=0, cnt=1; i<n; cnt++) {
            int p = i, j = 0;
            while (j<suf[p]) {
                if (vis[a[i]]<cnt) vis[a[i]]++;
                while (vis[j] == cnt) j++;
                i++;
            }
            if (!suf[p]) i++;
            ans.push_back(suf[p]);
        }
        cout << ans.size() << '\n';
        for (int x : ans) cout << x << ' ';
        cout << '\n';
    }
}