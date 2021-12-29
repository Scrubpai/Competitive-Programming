#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
typedef long long ll;
#define f first
#define s second
const int MM = 1e6;
int N, top[MM], bot[MM]; ll ans; vector<pi> lft[MM+1], rit[MM+1];
void update(int p, int v, int bit[]) { for (; p<=MM; p+=p&-p) bit[p]+=v; }
int query(int p, const int bit[]) { int ret=0; for (; p; p-=p&-p) ret+=bit[p]; return ret; }
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N;
    for (int i=1, a, b, c, d; i<=N; i++) {
        cin >> a >> b >> c >> d;
        lft[a].push_back({b, d}); rit[c].push_back({b, d});
    }
    for (int i=1; i<=MM; i++) {
        for (pi p : rit[i]) {
            ans += query(p.s-1, bot) - query(p.f, top) - 1;
            update(p.f, -1, bot); update(p.s, -1, top);
        }
        for (pi p : lft[i]) update(p.f, 1, bot), update(p.s, 1, top);
    }
    printf("%lld\n", ans);
}