#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 5005;
struct line {
    int a, b1, b2;
    bool operator < (const line &other) const {
        if (b1 != other.b1) return b1 < other.b1;
        else return a < other.a;
    }
};
void update(ll bit[], int p, ll v, int n) { for (; p<=n; p+=p&-p) bit[p]+=v; }
ll query(ll bit[], int p) { ll ret = 0; for (; p>=1; p-=p&-p) ret+=bit[p]; return ret; }
int H, V, cnt; ll bit1[3*MM], bit2[3*MM]; map<int, int> mp;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> H >> V; vector<line> horiz(H), vert(V), sweep; //sweep = {type(h=0, v=1), pos, idx}
    for (int i=0; i<H; i++) {
        cin >> horiz[i].a >> horiz[i].b1 >> horiz[i].b2;
        mp[horiz[i].b1] = 0; mp[horiz[i].b2] = 0;
        sweep.push_back({0, horiz[i].a, i});
    }
    for (int i=0; i<V; i++) {
        cin >> vert[i].a >> vert[i].b1 >> vert[i].b2;
        mp[vert[i].a] = 0;
        sweep.push_back({1, vert[i].b2, i});
    }
    for (auto &x: mp) x.second = ++cnt;
    for (int i=0; i<H; i++) {
        horiz[i].b1 = mp[horiz[i].b1];
        horiz[i].b2 = mp[horiz[i].b2];
    }
    for (int i=0; i<V; i++) {
        vert[i].a = mp[vert[i].a];
    }
    sort(sweep.begin(), sweep.end());
    ll ans = 0;
    for (int i=0; i<H; i++) {
        int y1 = horiz[i].a, x1l = horiz[i].b1, x1r = horiz[i].b2;
        for (int j=0; j<V; j++) {
            int x2 = vert[j].a, y2l = vert[j].b1, y2r = vert[j].b2;
            if (x2 >= x1l && x2 <= x1r && y2r >= y1 && y2l <= y1) {
                ll x = query(bit1, x2) - query(bit1, x2-1);
                update(bit2, x2, x, cnt);
                update(bit1, x2, 1, cnt);
            }
        }
        for (line e: sweep) {
            int tp = e.a, p = e.b1, idx = e.b2;
            if (tp == 0) { //horizantal
                if (p <= y1) continue;
                int x2l = horiz[idx].b1, x2r = horiz[idx].b2;
                int r = min(x1r, x2r), l = max(x1l, x2l);
                if (r > l) {
                    ll tot = query(bit1, r) - query(bit1, l-1), sub = query(bit2, r) - query(bit2, l-1);
                    ans += 1ll*tot*(tot-1)/2 - sub;
                }
            } else { //vertical
                int x2 = vert[idx].a, y2l = vert[idx].b1, y2r = vert[idx].b2;
                if (x2 >= x1l && x2 <= x1r && y2r >= y1 && y2l <= y1) {
                    update(bit1, x2, -1, cnt);
                    ll x = query(bit1, x2) - query(bit1, x2-1);
                    update(bit2, x2, -x, cnt);
                }
            }
        }
    }
    cout << ans << '\n';
}