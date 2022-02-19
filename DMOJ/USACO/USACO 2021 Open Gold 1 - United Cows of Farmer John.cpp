#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 2e5+5;
int N, b[MM], last[MM], bit[MM]; ll ans;
void update(int p, int v) { for (; p<=N; p+=p&-p) bit[p]+=v; }
int query(int p) { int ret=0; for (;p>=1; p-=p&-p) ret+=bit[p]; return ret; }
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N; memset(last, -1, sizeof(last));
    for (int i=1; i<=N; i++) {
        cin >> b[i];
        if (last[b[i]] == -1) {
            ans += query(i);
        } else {
            ans += query(i) - query(last[b[i]]);
            update(last[b[i]], -1);
        }
        last[b[i]] = i; update(i, 1);
    }
    cout << ans << '\n';
}