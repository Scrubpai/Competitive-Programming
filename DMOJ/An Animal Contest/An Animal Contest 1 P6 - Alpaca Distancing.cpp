#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
#define f first
#define s second
const int MM = 1e5+5;
int N, bit[3*MM], dp[MM], ans;
void update(int p, int v) { for (; p<=3*N; p+=p&-p) bit[p] = max(bit[p], v); }
int query(int p) { int ret = 0; for (; p>=1; p-=p&-p) ret = max(ret, bit[p]); return ret; }
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N; vector<pi> alp(N), id(N); vector<int> comp;
    comp.push_back(-1);
    for (int i=0; i<N; i++) {
        cin >> alp[i].f >> alp[i].s;
        comp.push_back(alp[i].f); comp.push_back(alp[i].f - alp[i].s); comp.push_back(alp[i].f + alp[i].s);
    }
    sort(comp.begin(), comp.end()); sort(alp.begin(), alp.end());
    comp.resize(unique(comp.begin(), comp.end()) - comp.begin());
    for (int i=0; i<N; i++) id[i] = {alp[i].f - alp[i].s, i};
    sort(id.begin(), id.end());
    for (int i=0, j=0; i<N; i++) {
        while (j<N && id[j].f < alp[i].f) {
            int p = lower_bound(comp.begin(), comp.end(), alp[id[j].s].f) - comp.begin();
            dp[id[j].s] = query(p) + 1;
            j++;
        }
        int r = lower_bound(comp.begin(), comp.end(), alp[i].f + alp[i].s) - comp.begin();
        update(r, dp[i]);
        ans = max(ans, dp[i]);
    }
    cout << ans << '\n';
}