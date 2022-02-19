#include <bits/stdc++.h>
using namespace std;
const int MM = 1e6+5;
int N, M, Q, ans; vector<int> virus, gaps;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N >> M >> Q;
    for (int i=0, v; i<Q; i++) { cin >> v; virus.push_back(v); }
    sort(virus.begin(), virus.end());
    for (int i=1; i<(int)virus.size(); i++) {
        if (virus[i] != virus[i-1]+1) gaps.push_back(virus[i]-virus[i-1]-1);
    }
    sort(gaps.begin(), gaps.end());
    for (int i=0; i<(int)gaps.size()+1-M; i++) ans += gaps[i];
    cout << ans+Q << '\n';
}