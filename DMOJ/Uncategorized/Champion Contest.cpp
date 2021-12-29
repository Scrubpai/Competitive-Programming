#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
const int MM = 1e5+5;
int n, k, ans[MM], cnt[MM];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> k; vector<pi> v(n);
    for (int i=0; i<n; i++) { cin >> v[i].first; v[i].second = i; }
    for (int i=0, a, b; i<k; i++) {
        cin >> a >> b; a--; b--;
        if (v[a].first > v[b].first) cnt[a]++;
        else if (v[b].first > v[a].first) cnt[b]++;
    }
    sort(v.begin(), v.end());
    int pre = 0;
    for (int i=0; i<n; i++) {
        if (v[i].first != v[pre].first) pre = i;
        ans[v[i].second] = pre - cnt[v[i].second];
    }
    for (int i=0; i<n; i++) cout << ans[i] << ' ';
}