#include <bits/stdc++.h>
using namespace std;
#define nl '\n'

struct E {
    int x1, y1, x2, y2;
};
bool cmp(E a, E b) {
    if (a.x1 != b.x1) return a.x1 < b.x1;
    else if (a.y1 != b.y1) return a.y1 < b.y1;
    else if (a.x2 != b.x2) return a.x2 < b.x2;
    else return a.y2 < b.y2;
}

vector<E> a;

void solve (int tc) {

    for (int i = 0, x1, y1, x2, y2; i < 4; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        if (x2 < x1 || (x1 == x2 && y2 < y1)) swap(x1, x2), swap(y1, y2);
        a.push_back({x1, y1, x2, y2});
    }
    sort(a.begin(), a.end(), cmp);
    if (a[0].x1 != a[0].x2 || a[0].y1 == a[0].y2) { cout << "NO" << nl; return; }
    if (a[1].y1 != a[1].y2 || a[1].x1 == a[1].x2) { cout << "NO" << nl; return; }
    if (a[2].y1 != a[2].y2 || a[2].x1 == a[2].x2) { cout << "NO" << nl; return; }
    if (a[3].x1 != a[3].x2 || a[3].y1 == a[3].y2) { cout << "NO" << nl; return; }

    if (a[0].x1 != a[1].x1 || a[0].y1 != a[1].y1) { cout << "NO" << nl; return; }
    if (a[0].x2 != a[2].x1 || a[0].y2 != a[2].y1) { cout << "NO" << nl; return; }
    if (a[2].x2 != a[3].x2 || a[2].y2 != a[3].y2) { cout << "NO" << nl; return; }
    if (a[1].x2 != a[3].x1 || a[1].y2 != a[3].y1) { cout << "NO" << nl; return; }
    cout << "YES";

}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}