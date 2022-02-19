#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+5;
typedef long long ll;
int N, Q; ll cnt[MM];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N >> Q;
    for (int i=1, a; i<=N; i++) { cin >> a; cnt[a]++; }
    for (int i=1, op, x; i<=Q; i++) {
        cin >> op >> x;
        if (op == 1) cnt[(x+1)/2] += cnt[x], cnt[x/2] += cnt[x], cnt[x] = 0;
        else cout << cnt[x] << '\n';
    }
}