#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
struct pt1 { int i, x, y; };
struct pt2 { int i, x, y; };
bool cmp1(pt1 a, pt1 b) { return a.y < b.y; }
bool cmp2(pt2 a, pt2 b) { return a.x < b.x; }
int N, ans[1005]; bool done[1005]; vector<pt1> east; vector<pt2> north; char dir;
void solve(int tc) {
    cin >> N;
    for (int i = 1, x, y; i <= N; i++) {
        cin >> dir >> x >> y;
        if (dir == 'E') east.push_back({i, x, y});
        else north.push_back({i, x, y});
    }
    sort(east.begin(), east.end(), cmp1); sort(north.begin(), north.end(), cmp2);
    for (pt1 p1 : east) {
        for (pt2 p2 : north) {
            if (p1.x >= p2.x || p2.y >= p1.y || done[p2.i]) continue;
            int POIx = p2.x, POIy = p1.y;
            if (POIx - p1.x == POIy - p2.y) continue;
            else if (POIx - p1.x < POIy - p2.y) {
                done[p2.i] = 1;
                ans[p1.i] += 1 + ans[p2.i];
            } else if (POIx - p1.x > POIy - p2.y) {
                done[p1.i] = 1;
                ans[p2.i] += 1 + ans[p1.i];
                break;
            }
        }
    }
    for (int i = 1; i <= N; i++) cout << ans[i] << nl;
}
int32_t main() {
    //freopen("", "r", stdin); freopen("", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}