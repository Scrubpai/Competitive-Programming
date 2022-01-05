#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
int N, K, pre, ans; set<int> blocks; vector<int> gaps;
void solve(int tc) {
    cin >> N >> K;
    for (int i=0, y; i<N; i++) { cin >> y; blocks.insert((y+11)/12); }
    ans = *blocks.rbegin();
    while (!blocks.empty()) {
        gaps.push_back(*blocks.begin() - pre - 1);
        pre = *blocks.begin();
        blocks.erase(*blocks.begin());
    }
    sort(gaps.rbegin(), gaps.rend());
    for (int i=0; i<K-1 && i<gaps.size(); i++) ans -= gaps[i];
    cout << ans * 12 << nl;
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int tc = 1; /*cin >> tc;*/ for (int t = 1; t <= tc; t++) solve(t); return 0; }