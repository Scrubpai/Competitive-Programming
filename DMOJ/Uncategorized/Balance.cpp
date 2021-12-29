#include <bits/stdc++.h>
using namespace std;
const int MM = 1e4;
int n, sum, ans; bool vis[MM+1];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n; vis[0] = 1;
    for (int i=1, v; i<=n; i++) {
        cin >> v; sum += v;
        for (int j=MM; j>=v; j--) vis[j] = max(vis[j], vis[j-v]);
    }
    for (int i=sum/2; ;i--) {
        if (vis[i]) { ans=i; break; }
    }
    printf("%d\n", sum-2*ans);
}