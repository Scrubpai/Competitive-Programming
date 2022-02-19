#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    for (int tt= 0; tt<10; tt++) {
        int N, M, D; cin >> N >> M >> D; vector<int> days(D+1);
        for (int i=1, a; i<=M; i++) { cin >> a; days[a]++; }
        int ans = 0, cur = N;
        for (int i=1; i<=D; i++) {
            if (!cur) ans++, cur=N;
            cur--; cur+=days[i]; N+=days[i];
        }
        cout << ans << '\n';
    }
}